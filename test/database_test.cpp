// Author : Akide Liu
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description :

//

#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>

#include <dao/include/databaseTables.h>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/select.h>
#include <sqlpp11/mysql/mysql.h>

namespace mysql = sqlpp::mysql;

using namespace std;

mysql::connection getConnection() {
    auto config = std::make_shared<mysql::connection_config>();
    config->host = "172.16.0.78";
    config->password = "LJi8kLPc2KaGjEJF";
    config->user = "oop";
    config->database = "oop";
    config->debug = true;

    mysql::connection db(config);

    return db;
}


TEST(database,test01){

    mysql::global_library_init();

    try
    {
        mysql::connection db = getConnection();
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
        mysql::connection db = getConnection();

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
        mysql::connection db = getConnection();

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
        mysql::connection db = getConnection();

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
        mysql::connection db = getConnection();

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
        mysql::connection db = getConnection();

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
        mysql::connection db = getConnection();

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





