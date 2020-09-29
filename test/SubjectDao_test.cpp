// Author : Akide Liu 
// Date : 28/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>

#include <dao/include/SubjectDao.h>
#include <database_connection.h>


TEST(SubjectDao_test,listAllSubjects){

    vector<string> check {"subject01","subject02"};

    vector<Subject *> result = SubjectDao::listAllSubjects();


    for (size_t i = 0; i < check.size(); ++i) {
        ASSERT_EQ(result[i]->getSubjectName(), check[i]);
    }
}

TEST(SubjectDao_test,selectOneSubject){

    map<int, string> check = {
            {1, "subject01"},
            {2,"subject02"},
    };

    for (const auto &kv : check) {

        Subject *s = SubjectDao::selectOneSubject(kv.first);

        EXPECT_EQ(s->getSubjectName(),kv.second);

        delete s;

    }

    Subject *s = SubjectDao::selectOneSubject(-1);

    EXPECT_EQ(s, nullptr);

    delete s;
}

TEST(SubjectDao_test,selectSubjectByName){
    vector<string> check01 {"subject01", "subject02"};

    vector<Subject *> result01 = SubjectDao::selectSubjectByName("subject");

    for (int i = 0; i < check01.size(); ++i) {
        EXPECT_EQ(check01[i], result01[i]->getSubjectName());
    }


    vector<Subject *> result02 = SubjectDao::selectSubjectByName("IcanNotBeFound");

    ASSERT_EQ(result02.size(),0);

}

TEST(SubjectDao_test,addNewSubject){
    Subject *check01 = new Subject(0, "test_subject");

    bool result01 = SubjectDao::addNewSubject(check01);

    EXPECT_EQ(result01, true);

    vector<Subject *> result02 = SubjectDao::selectSubjectByName(check01-> getSubjectName());

    EXPECT_EQ(result02.size(),1);
    EXPECT_EQ(result02[0]->getSubjectName(), "test_subject");

    mysql::connection db = database_connection::getConnection();

    db.execute(
            "delete peopleSubject.* from peopleSubject where peopleSubject.subject_id in (select subject.subject_id  from subject where subject.name = 'test_subject');");

    db.execute("delete subject.* from subject where subject.name = 'test_subject';");

    delete check01;

}

TEST(SubjectDao_test,updatePeopleToSubject){

    bool result01 = SubjectDao::updatePeopleToSubject(1, 2);

    EXPECT_EQ(result01,true);

    bool result02 = SubjectDao::updatePeopleToSubject(1, 1);

    EXPECT_EQ(result02, false);

    mysql::connection db = database_connection::getConnection();


    db.execute(
            "delete peopleSubject.* from peopleSubject where peopleSubject.subject_id = 2 and peopleSubject.user_id = 1;");
}


