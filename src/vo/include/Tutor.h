// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef CPP_TUTOR_H
#define CPP_TUTOR_H

class Tutor : public People {
private:
    const int userLevel = 2;
public:
    int getUserLevel() const override;
//TODO: need to replace by database
    Tutor(int userId, const string &name, const string &password = "-1", const string &title = Storage::title_array[2], bool isActive = true, int userLevel = 2);

};


#endif //CPP_TUTOR_H
