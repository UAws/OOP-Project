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
#include <vector>
#include <random>

#include <service/include/SERVICE_PUBLIC.h>
#include <database_connection.h>

// generate random string
// https://stackoverflow.com/a/47978023
// https://inversepalindrome.com/blog/how-to-create-a-random-string-in-cpp

string random_string()
{
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(str.begin(), str.end(), generator);

    return str.substr(0, 5);    // assumes 32 < number of characters in str
}


TEST(SubjectServices, listAllSubjects) {
    testing::internal::CaptureStdout();

    SubjectServices::listAllSubjects();

    string output = testing::internal::GetCapturedStdout();


    EXPECT_TRUE(output.find("SubjectID") != string::npos);
    EXPECT_TRUE(output.find("SubjectName") != string::npos);
    EXPECT_TRUE(output.find("subject01") != string::npos);
    EXPECT_TRUE(output.find("subject02") != string::npos);

}


TEST(SubjectServices, displayOneSubject) {
    {
        testing::internal::CaptureStdout();

        SubjectServices::displayOneSubject(1);

        string output = testing::internal::GetCapturedStdout();

        EXPECT_TRUE(output.find("SubjectID") != string::npos);
        EXPECT_TRUE(output.find("SubjectName") != string::npos);
        EXPECT_TRUE(output.find("subject01") != string::npos);

    }

    {
        testing::internal::CaptureStdout();

        SubjectServices::displayOneSubject(2);

        string output = testing::internal::GetCapturedStdout();


        EXPECT_TRUE(output.find("SubjectID") != string::npos);
        EXPECT_TRUE(output.find("SubjectName") != string::npos);
        EXPECT_TRUE(output.find("subject02") != string::npos);
    }

    {
        //CaptureStderr not CaptureStdout
        testing::internal::CaptureStderr();

        SubjectServices::displayOneSubject(3);

        string output = testing::internal::GetCapturedStderr();

        EXPECT_TRUE(output.find("The subject ID : 3 not found") != string::npos);

    }

}


TEST(SubjectServices, displaySubjectByName) {
    {
        testing::internal::CaptureStdout();

        SubjectServices::displaySubjectByName("subject");

        string output = testing::internal::GetCapturedStdout();

        EXPECT_TRUE(output.find("SubjectID") != string::npos);
        EXPECT_TRUE(output.find("SubjectName") != string::npos);
        EXPECT_TRUE(output.find("subject01") != string::npos);
        EXPECT_TRUE(output.find("subject02") != string::npos);
    }

    {

        testing::internal::CaptureStderr();

        SubjectServices::displaySubjectByName("IcanNotBeFound");

        string output = testing::internal::GetCapturedStderr();

        EXPECT_TRUE(output.find("The subject name : IcanNotBeFound not found") != string::npos);
    }
}


TEST(SubjectServices, addNewSubject) {

    vector<string> check;

    mysql::connection db = database_connection::getConnection();

    for (int i = 0; i < 5; ++i) {
        check.push_back(random_string());

        testing::internal::CaptureStdout();

        bool flag = SubjectServices::addNewSubject(check[i]);

        string output = testing::internal::GetCapturedStdout();

        //Check if a string contains a string in C++
        //https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c

        EXPECT_TRUE(output.find("The subject added successfully") != string::npos);
        EXPECT_TRUE(output.find("SubjectID") != string::npos);
        EXPECT_TRUE(output.find("SubjectName") != string::npos);
        EXPECT_TRUE(output.find(check[i]) != string::npos);


        EXPECT_EQ(true,flag);

        db.execute(
                "delete peopleSubject.* from peopleSubject where peopleSubject.subject_id in (select subject.subject_id  from subject where subject.name = '"+check[i]+"');");

        db.execute("delete subject.* from subject where subject.name = '"+check[i]+"';");
    }

}
