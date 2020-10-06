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

#include <vo/include/VO_PUBLIC.h>
#include <service/include/SERVICE_PUBLIC.h>
#include <dao/include/PeopleDao.h>
#include <dao/include/SubjectDao.h>
#include <database_connection.h>


using namespace std;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

//init password successes
TEST(People_Services_input, initPassword01) {

    Storage::setSUserId(1);
    EXPECT_TRUE(PeopleServices::initPassword());

    People *p = PeopleDao::selectOnePeople(1);

    EXPECT_EQ(p->getPassword(), "password123");

    mysql::connection db = database_connection::getConnection();

    db.execute("UPDATE oop.people t SET t.password = '-1' WHERE t.user_id = 1;");

    delete p;

}

//init password failed and account locked
TEST(People_Services_input, initPassword02) {

    Storage::setSUserId(2);

    EXPECT_FALSE(PeopleServices::initPassword());

    People *p = PeopleDao::selectOnePeople(2);


    EXPECT_EQ(p->isActive1(),false);

    mysql::connection db = database_connection::getConnection();

    db.execute("UPDATE oop.people t SET t.isActive = true WHERE t.user_id = 2;");

    delete p;

}

//when user's password is not default value (-1);
TEST(People_Services_input,login01) {

    mysql::connection db = database_connection::getConnection();

    db.execute("UPDATE oop.people t SET t.password = '1';");

    vector<string> check{"1", "-1","1", "-1","1"};

    for(int i = 1; i < 5; i++){
        bool result =  PeopleServices::login(i, check[i - 1]);

        if(i < 5 && i%2 != 0){
            // bool result =  PeopleServices::login(1,"-1");
            EXPECT_EQ(result, true);
        } else {
            EXPECT_EQ(result, false);
        }


    }

    db.execute("UPDATE oop.people t SET t.password = '-1';");

}
// user need to reset password
// expect that password changed init successfully and login return ture
TEST(People_Services_input,login02){

    EXPECT_TRUE(PeopleServices::login(1, "-1"));

    People *p = PeopleDao::selectOnePeople(1);

    EXPECT_EQ(p->getPassword(), "password123");

    mysql::connection db = database_connection::getConnection();

    db.execute("UPDATE oop.people t SET t.password = '-1' WHERE t.user_id = 1;");

    delete p;
}

// user need to reset password
// expect that password changed init failed and login return false
// and account would be locked

TEST(People_Services_input,login03){

    EXPECT_FALSE(PeopleServices::login(2, "-1"));

    People *p = PeopleDao::selectOnePeople(2);

    EXPECT_EQ(p->isActive1(),false);

    mysql::connection db = database_connection::getConnection();

    db.execute("UPDATE oop.people t SET t.isActive = true WHERE t.user_id = 2;");

    delete p;
}