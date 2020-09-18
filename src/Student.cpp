// Author : Akide Liu 
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "include/PUBLIC.h"


Student::Student (int userId, const string &name, const string &password, const string &title, bool isActive, int userLevel) : People(userId, name, password, title, isActive), userLevel(userLevel){};

ostream &operator<<(ostream &os, const Student &student) {
    os << static_cast<const People &>(student)  << " userLevel: "
       << student.userLevel;
    return os;
}

int Student::getUserLevel() const {
    return this->userLevel;
}

void Student::showSubjects() {

    VariadicTable<int, string, string> vt({"Subject ID", "Subject name", "Enrollment"});

    for (const auto& kv : Storage::storageSubjects) {

        vector<int> tmp = kv.second.getUserIdEnrolled();

        /*
         * find an element in vector
         * reference :
         * https://thispointer.com/c-how-to-find-an-element-in-vector-and-get-its-index/
         */
        auto it = find(tmp.begin(), tmp.end(),
                                           Storage::getCurrentUser()->getUserId());
        if (it != tmp.end()) {
            vt.addRow(kv.second.getSubjectId(), kv.second.getSubjectName(), "enrolled");
        } else {
            vt.addRow(kv.second.getSubjectId(), kv.second.getSubjectName(), "unrolled");
        }
    }

    vt.print(std::cout);
}

vector<int> Student::getUserSubjectId() {
    return People::getUserSubjectId();
}
