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

#ifndef OOP_PROJECT_PEOPLESERVICESH_
#define OOP_PROJECT_PEOPLESERVICESH_

#include <iostream>
#include <vector>
#include <algorithm>

#include <prettyprint.hpp>
#include <vo/include/People.h>
#include <vo/include/VO_PUBLIC.h>

class PeopleServices {

public:
    /*
     * static utils functions
     */

    static bool logout(int user_id);

    static bool login(int user_id, string password);

    static bool initPassword();

    static bool changePassword(int user_id, const string password);

    static void ListAllUsers();

    static int checkUserLevelById(int user_id);

    static bool resetUserPasswordById(int user_id);//void to bool

    static bool lockUser(int user_id);

    static bool unlockUser(int user_id);

    static void showCommunication();

    /*
     * userAction functions
     */
    virtual ~PeopleServices();

//todo: need to replace to protected and fix tests

protected:

    virtual bool addNewTutor(Tutor *people);// change the object to tutor according to the form in peopledao_test.cpp

    virtual bool changeUserName(int user_id, string user_name);

    virtual bool addNewStudent(Student *people);// change the object to tutor according to the form in peopledao_test.cpp

    virtual bool addNewSubject(Subject *subject);

    virtual bool changeSubjectName(int subject_id, string subject_name);

    virtual void showStudents();

    virtual void showTutors();

    virtual void showSubjects();

    virtual bool showSubjectsEnrolledById(int user_id);


private:

    static int s_user_id;

    static int s_subject_id;

    static PeopleServices * currentUser;


};


#endif //OOP_PROJECT_PEOPLESERVICESH_
