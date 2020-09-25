// Author : Akide Liu 
// Date : 25/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "dao/include/PeopleDao.h"
#include <vo/include/VO_PUBLIC.h>

#include <dao/include/databaseTables.h>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/mysql/mysql.h>
#include <database_connection.h>

vector<People *> PeopleDao::listAllUsers() {

    vector<People *> result;

    const auto t_people = oop::People{};
    const auto t_peopleSubject = oop::PeopleSubject{};
    try
    {
        mysql::connection db = database_connection::getConnection();

        //select * from people where people.user_id IN (select user_id from peopleSubject);

        for (const auto &row : db(sqlpp::select(all_of(t_people)).from(t_people).where(t_people.userId.in
                (sqlpp::select(t_people.userId).from(t_peopleSubject))))) {

            // cout << "ID : " << row.userId << " name : " << row.name << " password "
            //      << row.password << " title : " << row.title << "isActive : " << row.isActive
            //      << "userLevel : " << row.userLevel << endl;

            result.push_back(new People(row.userId, row.name, row.password, row.title, row.isActive));

        }
    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return result;

}


vector<People *> PeopleDao::showAllStudents() {


    vector<People *> result;

    const auto t_people = oop::People{};
    try
    {
        mysql::connection db = database_connection::getConnection();

        //select * from people where people.user_id IN (select user_id from peopleSubject);

        for (const auto &row : db(sqlpp::select(all_of(t_people)).from(t_people).where(t_people.userLevel.in(1)))) {

            // cout << "ID : " << row.userId << " name : " << row.name << " password "
            //      << row.password << " title : " << row.title << "isActive : " << row.isActive
            //      << "userLevel : " << row.userLevel << endl;

            result.push_back(new Student(row.userId, row.name, row.password, row.title, row.isActive,row.userLevel));

        }
    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return result;

}

vector<People *> PeopleDao::showAllTutors() {
    vector<People *> result;

    const auto t_people = oop::People{};
    try
    {
        mysql::connection db = database_connection::getConnection();

        //select * from people where people.user_id IN (select user_id from peopleSubject);

        for (const auto &row : db(sqlpp::select(all_of(t_people)).from(t_people).where(t_people.userLevel.in(2)))) {

            // cout << "ID : " << row.userId << " name : " << row.name << " password "
            //      << row.password << " title : " << row.title << "isActive : " << row.isActive
            //      << "userLevel : " << row.userLevel << endl;

            result.push_back(new Tutor(row.userId, row.name, row.password, row.title, row.isActive,row.userLevel));

        }
    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return result;
}

vector<People *> PeopleDao::showAllTeachers() {
    vector<People *> result;

    const auto t_people = oop::People{};
    try
    {
        mysql::connection db = database_connection::getConnection();

        //select * from people where people.user_id IN (select user_id from peopleSubject);

        for (const auto &row : db(sqlpp::select(all_of(t_people)).from(t_people).where(t_people.userLevel.in(3)))) {

            // cout << "ID : " << row.userId << " name : " << row.name << " password "
            //      << row.password << " title : " << row.title << "isActive : " << row.isActive
            //      << "userLevel : " << row.userLevel << endl;

            result.push_back(new Teacher(row.userId, row.name, row.password, row.title, row.isActive,row.userLevel));

        }
    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return result;

}

People *PeopleDao::selectOnePeople(int id) {

    const auto t_people = oop::People{};

    bool flag = false;

    People * result ;

    try
    {
        mysql::connection db = database_connection::getConnection();

        // select people.* from people where people.user_id = 1;

        for (const auto &row : db(select(all_of(t_people)).from(t_people).where(t_people.userId == id))) {

            flag = true;

            switch (row.userLevel) {
                case 1 :
                    result = new Student(row.userId, row.name, row.password, row.title, row.isActive, row.userLevel);
                    break;

                case 2 :
                    result = new Tutor(row.userId, row.name, row.password, row.title, row.isActive, row.userLevel);
                    break;

                case 3 :
                    result = new Teacher(row.userId, row.name, row.password, row.title, row.isActive, row.userLevel);
                    break;

                default:
                    result = nullptr;
                    cerr << "PeopleDao error : people not found by ID : " << id << endl;
            }

        }
    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return flag ? result : nullptr;

}

//TODO: need more consideration
//this function may return multiple people or one people

vector<People *> PeopleDao::selectPeopleByName(string name) {
    const auto t_people = oop::People{};

    vector<People *> result ;

    try
    {
        mysql::connection db = database_connection::getConnection();

        // select people.* from people where people.userName = "Student";

        for (const auto &row : db(select(all_of(t_people)).from(t_people).where(t_people.name.like("%"+name+"%")))) {

            switch (row.userLevel) {
                case 1 :
                    result.push_back( new Student(row.userId, row.name, row.password, row.title, row.isActive, row.userLevel));
                    break;

                case 2 :
                    result.push_back( new Tutor(row.userId, row.name, row.password, row.title, row.isActive, row.userLevel));
                    break;

                case 3 :
                    result.push_back( new Teacher(row.userId, row.name, row.password, row.title, row.isActive, row.userLevel));
                    break;

                default:
                    // result = nullptr;
                    cerr << "PeopleDao error : people not found by name :  " << name << endl;
            }

        }
    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return result;
}

bool PeopleDao::addNewStudent(Student *student) {


    const auto t_people = oop::People{};

    try
    {
        mysql::connection db = database_connection::getConnection();

        // insert into people (name, password, title, isActive, userLevel)
        //      VALUES ('xiaoming', '-1', 'student', true, 1);

        db(insert_into(t_people).set(
                t_people.name = student->getName(),
                t_people.isActive = true,
                t_people.password = "-1",
                t_people.title="student",
                t_people.userLevel = student->getUserLevel())
                );

    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }

    return true;
}

bool PeopleDao::addNewTutor(Tutor *tutor) {
    const auto t_people = oop::People{};
    const auto t_peopleSubject = oop::PeopleSubject{};
    const auto t_subject = oop::Subject{};
    try
    {
        mysql::connection db = database_connection::getConnection();

        // insert into people (name, password, title, isActive, userLevel)
        //      VALUES ('xiaoming', '-1', 'student', true, 1);

        //insert into people table
        db(insert_into(t_people).set(
                t_people.name = tutor->getName(),
                t_people.isActive = true,
                t_people.password = "-1",
                t_people.title="tutor",
                t_people.userLevel = tutor->getUserLevel())
        );


        // auto enroll to all subject
        int subject_count = db(select(
                count(t_subject.subjectId)).from(t_subject).
                unconditionally()).front().count;

        int currentUserId = 0;

        for (const auto &row : db(select(t_people.userId).
            from(t_people).
            where(t_people.name == tutor->getName())
            )
            )
        {
            currentUserId = row.userId;
        }

        if (currentUserId == 0 ) {
            cerr << "PeopleDao error : people insert error " << endl;
            return false;
        }

        for (int i = 0; i < subject_count; ++i) {
            db(insert_into(t_peopleSubject).set(
                    t_peopleSubject.userId = currentUserId,
                    t_peopleSubject.subjectId = (i + 1)));
        }

    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }

    return true;
}

bool PeopleDao::addNewTeacher(Teacher *teacher) {
    const auto t_people = oop::People{};

    try
    {
        mysql::connection db = database_connection::getConnection();

        // insert into people (name, password, title, isActive, userLevel)
        //      VALUES ('xiaoming', '-1', 'student', true, 1);

        db(insert_into(t_people).set(
                t_people.name = teacher->getName(),
                t_people.isActive = true,
                t_people.password = "-1",
                t_people.title="teacher",
                t_people.userLevel = teacher->getUserLevel())
        );

    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }

    return true;
}

bool PeopleDao::updatePeoplePassword(int id, string password) {
    const auto t_people = oop::People{};

    try
    {
        mysql::connection db = database_connection::getConnection();

        // insert into people (name, password, title, isActive, userLevel)
        //      VALUES ('xiaoming', '-1', 'student', true, 1);

        db(update(t_people).set(t_people.password = password).where(t_people.userId.in(id)));

    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }

    return true;
}

bool PeopleDao::updatePeopleResetPassword(int id) {
    const auto t_people = oop::People{};

    try
    {
        mysql::connection db = database_connection::getConnection();

        // insert into people (name, password, title, isActive, userLevel)
        //      VALUES ('xiaoming', '-1', 'student', true, 1);

        db(update(t_people).set(t_people.password = "-1").where(t_people.userId.in(id)));

    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }

    return true;
}


bool PeopleDao::updatePeopleActive(int id, bool flag) {
    const auto t_people = oop::People{};

    try
    {
        mysql::connection db = database_connection::getConnection();

        // insert into people (name, password, title, isActive, userLevel)
        //      VALUES ('xiaoming', '-1', 'student', true, 1);

        db(update(t_people).set(t_people.isActive = flag).where(t_people.userId.in(id)));

    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }

    return true;
}
