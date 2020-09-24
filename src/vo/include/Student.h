// Author : Akide Liu
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef CPP_STUDENT_H
#define CPP_STUDENT_H


#include <ostream>

using namespace std;

class Student : public People {
private:
    const int userLevel = 1;
public:
    int getUserLevel() const override;

    Student(int userId, const string &name, const string &password = "-1", const string &title = "student", bool isActive = true, int userLevel = 1);

    friend ostream &operator<<(ostream &os, const Student &student);




};


#endif //CPP_STUDENT_H
