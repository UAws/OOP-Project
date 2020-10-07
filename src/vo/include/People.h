/*

Authors: Akide Liu ; Andrew Wang ; Chi Wang
Date : 24/9/20

OOP-Project
Copyright (C) <2020>  Akide Liu ; Andrew Wang ; Chi Wang

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

Description :

*/

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
