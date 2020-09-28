// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>

#include <vo/include/VO_PUBLIC.h>
#include <service/include/SERVICE_PUBLIC.h>
#include <dao/include/PeopleDao.h>



using namespace std;

TEST(major,test01){

    //TODO: storage need to change to dao by database
    for (const auto& kv : Storage::storagePeople) {
        std::cout << kv.first << " has value " << *kv.second <<" userLevel : "<<kv.second->getUserLevel()<<std::endl;
    }
    //TODO: need to replace by database
    for (const auto& kv : Storage::storageSubjects) {
        std::cout << kv.first << " has value " << kv.second <<std::endl;
    }

    //TODO: need to replace by database
    cout << Storage::title_array << std::endl;

    // Storage::setCurrentUserById(2);
    // Storage::storagePeople[2]->login(4, "-1");
    // Storage::storagePeople[2]->showStudents();
    // Storage::storagePeople[2]->addNewStudent(new Student(Storage::getSUserId(), "student02"));
    // Storage::storagePeople[2]->showStudents();
    //
    PeopleServices::ListAllUsers();

    PeopleServices *ps01 = new TutorServices();
    ps01->showStudents();



    //TODO: need to replace by database
    Storage::clearHeap();

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // ::testing::GTEST_FLAG(filter) = "database*";
    // ::testing::GTEST_FLAG(filter) = "major*";

    return RUN_ALL_TESTS();
}





TEST(major,login) {

    vector<string> check{"1", "-1","1", "-1","1"}; 

    for(int i = 1; i < 5; i++){
        bool result =  PeopleServices::login(i, check[i - 1]);

       if(i < 5 && i%2 == 0){
        // bool result =  PeopleServices::login(1,"-1");
        EXPECT_EQ(result, true);   
        } else {
        EXPECT_EQ(result, false);   
        }  


    }

}

TEST(People_Services,logout){
    for (int i = 1; i < 10; i++){
        if(i < 5){
            bool actual = PeopleServices::logout(i);
            EXPECT_EQ(actual,true);
        }
        if(i > 5){
            bool actual = PeopleServices::logout(i);
            EXPECT_EQ(actual,false);
        }
    }
}
ll
TEST(major, ListAllUsers) {

    PeopleServices check;

    testing::internal::CaptureStdout();
    check.ListAllUsers();
    string output = testing::internal::GetCapturedStdout();

    vector<string> arr;
    stringstream ss(output);
    string final_output;

    while (std::getline(ss, final_output, '\n')){
        arr.push_back(final_output);
    }

    EXPECT_EQ(arr[1],"| People ID | People name |  Title  | IsActive |");
    EXPECT_EQ(arr[3],"|         1 | student01   | student |        1 |");
    EXPECT_EQ(arr[4],"|         2 | tutor01     | tutor   |        1 |");
}