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

#ifndef CPP_SUBJECT_H
#define CPP_SUBJECT_H
#include <iostream>
#include <vector>

using namespace std;

class Subject {
private:
    int subject_id;
    string subject_name;


public:

    Subject();

    Subject(int subjectId, const string &subjectName);

    //getter and setter

    int getSubjectId() const;

    void setSubjectId(int subjectId);

    const string &getSubjectName() const;

    void setSubjectName(const string &subjectName);

    friend ostream &operator<<(ostream &os, const Subject &subject);

};


#endif //CPP_SUBJECT_H
