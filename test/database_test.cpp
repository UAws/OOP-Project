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

#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>

#include <dao/include/databaseTables.h>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/select.h>
#include <sqlpp11/mysql/mysql.h>
#include <database_connection.h>

namespace mysql = sqlpp::mysql;

using namespace std;


TEST(database,test01){

    mysql::global_library_init();

    try
    {
        mysql::connection db = database_connection::getConnection();
        cout << "Connection created successfully" << endl;
    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

TEST(database,test02){
    const auto people = oop::People{};
    try
    {
        mysql::connection db = database_connection::getConnection();

        for (const auto &row : db(sqlpp::select(people.userId, people.name).from(people).where(people.userId < 3 and people.userId > 0 ))) {
            cout << "ID : " << row.userId << " name : " << row.name << endl;
        }
    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

TEST(database,test03) {
    const auto people = oop::People{};
    const auto peopleSubject = oop::PeopleSubject{};
    try
    {
        mysql::connection db = database_connection::getConnection();

        //select * from people where people.user_id IN (select user_id from peopleSubject);

        for (const auto &row : db(sqlpp::select(all_of(people)).from(people).where(people.userId.in
                                (sqlpp::select(people.userId).from(peopleSubject))))) {

            cout << "ID : " << row.userId << " name : " << row.name << " password "
            << row.password << " title : " << row.title << "isActive : " << row.isActive
            << "userLevel : " << row.userLevel << endl;

        }
    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}

TEST(database,test04){
    // const auto people = oop::People{};
    const auto subject = oop::Subject{};
    const auto peopleSubject = oop::PeopleSubject{};
    try
    {
        mysql::connection db = database_connection::getConnection();

        // select * from subject where subject_id in (select subject_id from peopleSubject);


        for (const auto &row : db(sqlpp::select(all_of(subject)).from(subject).where(subject.subjectId.in(select(subject.subjectId).from(peopleSubject))))) {

            cout << "ID : " << row.subjectId << " name : " << row.name << endl;

        }
    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


// SQLPP_ALIAS_PROVIDER(Ps);

TEST(database,test05){
    const auto people = oop::People{};
    const auto subject = oop::Subject{};
    const auto peopleSubject = oop::PeopleSubject{};
    try
    {
        mysql::connection db = database_connection::getConnection();

        // select people.name from people
        // left join peopleSubject pS on people.user_id = pS.user_id
        // left join subject s on s.subject_id = pS.subject_id
        // where s.name='subject01';


        for (const auto &row : db(sqlpp::select(
                people.name
                ).from(people.join(peopleSubject).on(people.userId == peopleSubject.userId).
                    left_outer_join(subject).on(subject.subjectId == peopleSubject.subjectId)
                    ).where(subject.name == "subject01")
            )
        ) {

            cout << " name : " << row.name << endl;

        }
    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

TEST(database,test06){
    const auto people = oop::People{};
    const auto subject = oop::Subject{};
    const auto peopleSubject = oop::PeopleSubject{};
    try
    {
        mysql::connection db = database_connection::getConnection();

        /*
            select subject.* from
            subject left join peopleSubject pS on subject.subject_id = pS.subject_id
            left join people p on p.user_id = pS.user_id
            where p.name = 'student01';
         */

        for (const auto &row : db(sqlpp::select(
                all_of(subject)
                ).from(subject.join(peopleSubject).on(subject.subjectId == peopleSubject.subjectId).
                    left_outer_join(people).on(people.userId == peopleSubject.userId)
                    ).where(people.name == "student01")
            )
        )
        {

            cout << "ID : " << row.subjectId << " name : " << row.name << endl;

        }
    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
TEST(database,test07){
    const auto people = oop::People{};
    const auto subject = oop::Subject{};
    const auto peopleSubject = oop::PeopleSubject{};
    try
    {
        mysql::connection db = database_connection::getConnection();

        /*
            select subject.name from
                subject left join peopleSubject pS on subject.subject_id = pS.subject_id
                left join people p on p.user_id = pS.user_id
                where p.name = 'tutor01';
         */

        for (const auto &row : db(sqlpp::select(
                subject.name
                ).from(subject.join(peopleSubject).on(subject.subjectId == peopleSubject.subjectId).
                    left_outer_join(people).on(people.userId == peopleSubject.userId)
                    ).where(people.name == "tutor01")
            )
        )
        {

            cout << " name : " << row.name << endl;

        }
    }
    catch (const sqlpp::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}





