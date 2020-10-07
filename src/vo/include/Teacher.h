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
