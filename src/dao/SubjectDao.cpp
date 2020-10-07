/*

Authors: Akide Liu ; Andrew Wang ; Chi Wang
Date : 24/9/20

OOP-Project
Copyright (C) <2020>  Akide Liu ; Andrew Wang ; Chi Wang

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

Description :

*/

#include "dao/include/SubjectDao.h"
#include <dao/include/PeopleDao.h>
#include <vo/include/VO_PUBLIC.h>

#include <dao/include/databaseTables.h>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/mysql/mysql.h>
#include <database_connection.h>

vector<Subject *> SubjectDao::listAllSubjects() {

    vector<Subject *> result;
    const auto t_subject = oop::Subject{};

    try {

        mysql::connection db = database_connection::getConnection();

        for (const auto &row : db(sqlpp::select(all_of(t_subject)).from(t_subject).unconditionally())) {

            result.push_back(new Subject(row.subjectId, row.name));

        }

    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return result;
}

Subject *SubjectDao::selectOneSubject(int id) {


    const auto t_subject = oop::Subject{};

    bool flag = false;

    Subject *result;

    try {

        mysql::connection db = database_connection::getConnection();

        for (const auto &row : db(sqlpp::select(all_of(t_subject)).from(t_subject).where(t_subject.subjectId == id))) {

            flag = true;

            result = new Subject(row.subjectId, row.name);

        }
    }
    catch (const sqlpp::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return flag ? result : nullptr;

}


vector<Subject*> SubjectDao::selectSubjectByName(string name) {
    const auto t_subject = oop::Subject{};

    vector<Subject *> result;

    try {

        mysql::connection db = database_connection::getConnection();

        for (const auto &row : db(sqlpp::select(all_of(t_subject)).from(t_subject).where(t_subject.name.like("%"+name+"%")))) {


            result.push_back(new Subject(row.subjectId, row.name));

        }
    }
    catch (const sqlpp::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return result;
}

bool SubjectDao::addNewSubject(Subject *subject) {

    const auto t_people = oop::People{};
    const auto t_peopleSubject = oop::PeopleSubject{};
    const auto t_subject = oop::Subject{};

    try {

        mysql::connection db = database_connection::getConnection();

        db(insert_into(t_subject).set(
                t_subject.name = subject->getSubjectName()
                ));


        vector <int> userIDs;
        for (const auto &row : db(
                select(all_of(t_people)).from(t_people).where(t_people.userLevel == 2 || t_people.userLevel == 3))) {
            userIDs.push_back(row.userId);
        }

        int currentSubjectID = 0;

        for (const auto &row : db(select(all_of(t_subject)).
                from(t_subject).
                where(t_subject.name == subject->getSubjectName())
        )
                )
        {
            currentSubjectID = row.subjectId;
        }

        if (currentSubjectID == 0 ) {
            cerr << "SubjectDao error : Subject insert error " << endl;
            return false;
        }

        for (int userID : userIDs) {
            db(insert_into(t_peopleSubject).set(
                    t_peopleSubject.userId = userID,
                    t_peopleSubject.subjectId = currentSubjectID));
        }

    }
    catch (const sqlpp::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }

    return true;
}

bool SubjectDao::updatePeopleToSubject(int userId, int subjectId) {
    const auto t_peopleSubject = oop::PeopleSubject{};

    if (PeopleDao::selectOnePeople(userId) == nullptr
        || SubjectDao::selectOneSubject(subjectId)  == nullptr) {

        cerr << "PeopleDao error : updatePeopleToSubject" << endl;
        return false;

    }


    try {

        mysql::connection db = database_connection::getConnection();

        db(insert_into(t_peopleSubject).set(
                t_peopleSubject.userId = userId,
                t_peopleSubject.subjectId = subjectId
                ));
    }
    catch (const sqlpp::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }


    return true;
}



bool SubjectDao::updateSubjectName(int id, string name) {
    const auto t_subject = oop::Subject{};

    try
    {
        mysql::connection db = database_connection::getConnection();

        auto s = SubjectDao::selectOneSubject(id);

        if (s == nullptr) {
            return false;
        }
        // insert into people (name, password, title, isActive, userLevel)
        //      VALUES ('xiaoming', '-1', 'student', true, 1);

        db(update(t_subject).set(t_subject.name = std::move(name)).where(t_subject.subjectId.in(id)));

    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return true;
}
