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

#ifndef OOP_PROJECT_TEACHERSERVICES_H
#define OOP_PROJECT_TEACHERSERVICES_H

#include "PeopleServices.h"

class TeacherServices : public PeopleServices, public PeopleCommunications {

public:
    bool addNewTutor(Tutor *people) override;

    bool changeUserName(int user_id, string user_name) override;

    bool addNewStudent(Student *people) override;

    bool addNewSubject(Subject *subject) override;

    bool changeSubjectName(int subject_id, string subject_name) override;

    void showStudents() override;

    void showTutors() override;

    void showSubjects() override;

    bool showSubjectsEnrolledById(int user_id) override;

    void communicate(int messageId, string context) override;


};


#endif //OOP_PROJECT_TEACHERSERVICES_H
