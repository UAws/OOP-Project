// Author : Akide Liu 
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "include/PUBLIC.h"

int Tutor::getUserLevel() const {
    return this->userLevel;
}

Tutor::Tutor(int userId, const string &name, const string &password, const string &title, bool isActive,
             int userLevel) : People(userId, name, password, title, isActive), userLevel(userLevel){}

void Tutor::showStudents() {
    VariadicTable<int, string, string, bool,vector<int>> vt({"Student ID", "Student name", "Title", "IsActive", "Subject ID"});

    for (const auto& kv : Storage::storagePeople) {
        if (kv.second->getUserLevel() == 1) {
            People stu = *kv.second;
            vt.addRow(stu.getUserId(), stu.getName(), stu.getTitle(),stu.isActive1(),stu.getUserSubjectId());
        }
    }

    vt.print(cout);
}

void Tutor::addNewStudent(People *people) {
    Storage::storagePeople.insert(std::make_pair(people->getUserId(), people));
}

void Tutor::modifyStudentById(int user_id) {
    People::modifyStudentById(user_id);
}

