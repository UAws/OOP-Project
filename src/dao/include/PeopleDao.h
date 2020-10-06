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
#ifndef OOP_PROJECT_PEOPLEDAO_H
#define OOP_PROJECT_PEOPLEDAO_H

#include <vo/include/VO_PUBLIC.h>

class PeopleDao {
public:

    // list
    static vector<People *> listAllUsers();

    static vector<People *> showAllStudents();

    static vector<People *> showAllTutors();

    static vector<People *> showAllTeachers();


    // select

    static People *selectOnePeople(int id);

    static vector<People *> selectPeopleByName(string name);

    static pair<People *, vector<Subject *>> selectSubjectPeopleEnrolledByUserId(int id);



    //insert

    static bool addNewStudent(Student *student);

    static bool addNewTutor(Tutor *tutor);

    static bool addNewTeacher(Teacher *teacher);


    //update

    static bool updatePeopleName(int id, string name);

    static bool updatePeoplePassword(int id, string password);

    static bool updatePeopleResetPassword(int id);

    static bool updatePeopleActive(int id, bool flag);



};


#endif //OOP_PROJECT_PEOPLEDAO_H
