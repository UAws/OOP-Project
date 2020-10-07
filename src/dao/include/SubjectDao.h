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

#ifndef OOP_PROJECT_SUBJECTDAO_H
#define OOP_PROJECT_SUBJECTDAO_H

#include <vo/include/VO_PUBLIC.h>

class SubjectDao {
public:
    // list

    static vector<Subject*> listAllSubjects();

    // select

    static Subject* selectOneSubject(int id);

    static vector<Subject*> selectSubjectByName(string name);

    //insert

    static bool addNewSubject(Subject *subject);

    //update

    static bool updatePeopleToSubject(int userId, int subjectId);


    static bool updateSubjectName(int id, string name);
};


#endif //OOP_PROJECT_SUBJECTDAO_H
