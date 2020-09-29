// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef CPP_TEACHER_H
#define CPP_TEACHER_H

class Teacher : public People{
private:
    const int userLevel = 3;
public:
    int getUserLevel() const override;

    //TODO: need to replace by database//TODO: need to replace by database
    Teacher(int userId, const string &name, const string &password = "-1", const string &title = "teacher", bool isActive = true, int userLevel = 3);
};


#endif //CPP_TEACHER_H
