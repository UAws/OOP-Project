// Author : Akide Liu 
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "include/VO_PUBLIC.h"

int Teacher::getUserLevel() const {
    return this->userLevel;
}

Teacher::Teacher(int userId, const string &name, const string &password, const string &title, bool isActive,
                 int userLevel) : People(userId, name, password, title, isActive), userLevel(userLevel) {

}
