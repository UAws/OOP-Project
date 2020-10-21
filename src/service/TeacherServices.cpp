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
#include <dao/include/SubjectDao.h>
#include <dao/include/PeopleDao.h>
#include <service/include/SERVICE_PUBLIC.h>
#include <vo/include/VO_PUBLIC.h>


bool TeacherServices::addNewTutor(Tutor *people) {
    return PeopleServices::addNewTutor(people);
}

bool TeacherServices::changeUserName(int user_id, string user_name) {
    return PeopleServices::changeUserName(user_id, user_name);
}

bool TeacherServices::addNewStudent(Student *people) {
    return PeopleServices::addNewStudent(people);
}

bool TeacherServices::addNewSubject(Subject *subject) {
    return PeopleServices::addNewSubject(subject);
}

bool TeacherServices::changeSubjectName(int subject_id, string subject_name) {
    return PeopleServices::changeSubjectName(subject_id, subject_name);
}

void TeacherServices::showStudents() {
    PeopleServices::showStudents();
}

void TeacherServices::showTutors() {
    PeopleServices::showTutors();
}

void TeacherServices::showSubjects() {
    PeopleServices::showSubjects();
}

bool TeacherServices::showSubjectsEnrolledById(int user_id) {
    return PeopleServices::showSubjectsEnrolledById(user_id);
}

// set the message id

void TeacherServices::communicate(int messageId, string context) {

    messageId -= 1;


    auto currentMessage = Storage::messageArray[messageId];

    auto check = PeopleDao::selectSubjectPeopleEnrolledByUserId(currentMessage->getStudentId());

    bool checkFlag = true;
    for (auto &i : check.second) {

        if (i->getSubjectId() == currentMessage->getRequestSubjectId()) {

            cout << *Storage::messageArray[messageId] << " student already in this subject" << endl;

            checkFlag = false;

            break;
        }
    }


    if (checkFlag) {
        if (context == "1") {

            if (SubjectDao::updatePeopleToSubject(currentMessage->getStudentId(),
                                                  currentMessage->getRequestSubjectId())) {
                Storage::messageArray[messageId]->setApprove("approved");
                cout << *Storage::messageArray[messageId] << " request approved!" << endl;

            }

        } else {

            Storage::messageArray[messageId]->setApprove("denied");

            cout << *Storage::messageArray[messageId] << " denied!" << endl;

        }
    }

}
