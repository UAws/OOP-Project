// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef CPP_PEOPLE_H
#define CPP_PEOPLE_H

#include <iostream>
#include <vector>
#include <algorithm>

#include <prettyprint.hpp>
#include "Subject.h"

using namespace std;

class People {
public:
    /*
     * constructor and destructor
     */
    People();

    People(int userId, const string &name, const string &password, const string &title, bool isActive);

    People(const string &name, const string &title);

    virtual ~People();
    

    /*
     * object getter and setter
     */

    virtual int getUserId() const;

    virtual void setUserId(int userId);

    virtual const string &getName() const;

    virtual void setName(const string &name);

    virtual const string &getPassword() const;

    virtual void setPassword(const string &password);

    virtual const string &getTitle() const;

    virtual void setTitle(const string &title);

    virtual bool isActive1() const;

    virtual void setIsActive(bool isActive);

    virtual int getUserLevel() const;

    virtual void setUserLevel(int userLevel);

    friend ostream &operator<<(ostream &os, const People &people);




protected:
        /* level : 1 --> student
         * level : 2 --> tutor
         * level : 3 --> teacher    */

    int userLevel;
    int user_id;
    string name;
    string password = "-1";
    string title;
    bool isActive;

};


#endif //CPP_PEOPLE_H
