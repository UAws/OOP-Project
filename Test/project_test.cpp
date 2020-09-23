// Author : Akide Liu 
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>

#include "../src/include/PUBLIC.h"

using namespace std;

TEST(major,test01){


    for (const auto& kv : Storage::storagePeople) {
        std::cout << kv.first << " has value " << *kv.second <<" userLevel : "<<kv.second->getUserLevel()<<std::endl;
    }
    //
    // for (const auto& kv : Storage::storageSubjects) {
    //     std::cout << kv.first << " has value " << kv.second <<std::endl;
    // }

    // cout << Storage::title_array << std::endl;

    Storage::setCurrentUserById(2);
    // Storage::storagePeople[2]->login(4, "-1");
    Storage::storagePeople[2]->showStudents();
    Storage::storagePeople[2]->addNewStudent(new Student(Storage::getSUserId(), "student02"));
    Storage::storagePeople[2]->showStudents();

    People::ListAllUsers();



    Storage::clearHeap();

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // ::testing::GTEST_FLAG(filter) = "database*";
    // ::testing::GTEST_FLAG(filter) = "major*";

    return RUN_ALL_TESTS();
}