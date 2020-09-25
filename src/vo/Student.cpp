// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "include/VO_PUBLIC.h"


Student::Student (int userId, const string &name, const string &password, const string &title, bool isActive, int userLevel) : People(userId, name, password, title, isActive), userLevel(userLevel){};

ostream &operator<<(ostream &os, const Student &student) {
    os << static_cast<const People &>(student) << " userLevel: "
       << student.userLevel;
    return os;
}

int Student::getUserLevel() const {
    return this->userLevel;
}


