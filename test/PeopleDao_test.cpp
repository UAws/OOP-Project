// Author : Akide Liu 
// Date : 26/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//
#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>

#include <dao/include/PeopleDao.h>
#include <database_connection.h>

TEST(PeopleDao_test,listAllUsers) {

    //vector<string> check {"student01","tutor01","teacher01","student02","tutor02"};

    vector<People*> result = PeopleDao::listAllUsers();

    for (size_t i = 0; i < check.size(); ++i) {
        ASSERT_EQ(result[i]->getName(),check[i]);
    }

    // cout << result << endl;

}


TEST(PeopleDao_test, showAllStudents) {

    vector<string> check {"student01", "student02"};

    vector<People*> result = PeopleDao::showAllStudents();

    for (size_t i = 0; i < check.size(); ++i) {
        ASSERT_EQ(result[i]->getName(),check[i]);
    }

}


TEST(PeopleDao_test, showAllTutors) {

    vector<string> check {"tutor01", "tutor02"};

    vector<People*> result = PeopleDao::showAllTutors();

    for (size_t i = 0; i < check.size(); ++i) {
        ASSERT_EQ(result[i]->getName(),check[i]);
    }

}

TEST(PeopleDao_test, showAllTeachers) {

    vector<string> check {"teacher01"};

    vector<People*> result = PeopleDao::showAllTeachers();

    for (size_t i = 0; i < check.size(); ++i) {
        ASSERT_EQ(result[i]->getName(),check[i]);
    }

}

TEST(PeopleDao_test,selectOnePeopleById) {

    map<int, string> check = {
            {1, "student01"},
            {2,"tutor01"},
            {3,"teacher01"},
    };


    for (const auto& kv : check) {
        People* p = PeopleDao::selectOnePeople(kv.first);

        ASSERT_EQ(p->getName(),kv.second);

        delete p;
    }

    People *p = PeopleDao::selectOnePeople(-1);

    ASSERT_EQ(p, nullptr);

    delete p;
}

TEST(PeopleDao_test,selectPeopleByName) {
    vector<string> check01{"student01", "student02"};
    vector<People *> result01 = PeopleDao::selectPeopleByName("student");

    for (size_t i = 0; i < check01.size(); ++i) {
        ASSERT_EQ(check01[i], result01[i]->getName());
    }

    vector<People *> result02 = PeopleDao::selectPeopleByName("IcanNotBeFound");
    ASSERT_EQ(result02.size(),0);
}

TEST(PeopleDao_test,addNewStudent){

    //user id automatically increased and managed by database

    Student *check01 = new Student(0, "test");

    bool result01 =  PeopleDao::addNewStudent(check01);

    EXPECT_EQ(result01, true);

    vector<People *> result02 = PeopleDao::selectPeopleByName(check01->getName());

    EXPECT_EQ(result02.size(),1);
    EXPECT_EQ(result02[0]->getName(), "test");
    EXPECT_EQ(result02[0]->getUserLevel(), 1);
    EXPECT_EQ(result02[0]->getPassword(), "-1");
    EXPECT_EQ(result02[0]->getTitle(), "student");
    EXPECT_EQ(result02[0]->isActive1(), true);


    mysql::connection db = database_connection::getConnection();

    db.execute("delete people.* from people where people.name = 'test';");

    delete check01;

}



