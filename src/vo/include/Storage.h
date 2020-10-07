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

#ifndef CPP_STORAGE_H
#define CPP_STORAGE_H

#include <iostream>
#include <vector>
#include <map>
#include "People.h"

//TODO: need to replace by database
using namespace std;

class Storage {

public:

    static int getSUserId();

    static void setSUserId(int sUserId);

    static int getSSubjectId();

    static void setSSubjectId(int sSubjectId);


private:

    static int s_user_id;

    static int s_subject_id;

};


#endif //CPP_STORAGE_H
