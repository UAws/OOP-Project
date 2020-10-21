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

#include <service/include/SERVICE_PUBLIC.h>
#include <vo/include/VO_PUBLIC.h>
#include <dao/include/PeopleDao.h>


bool TutorServices::changeUserName(int user_id, string user_name) {
    return PeopleServices::changeUserName(user_id, user_name);
}

bool TutorServices::addNewStudent(Student *people) {
    return PeopleServices::addNewStudent(people);
}

void TutorServices::showStudents() {
    PeopleServices::showStudents();
}

void TutorServices::showSubjects() {
    PeopleServices::showSubjects();
}

bool TutorServices::showSubjectsEnrolledById(int user_id) {
    return PeopleServices::showSubjectsEnrolledById(user_id);
}

void TutorServices::communicate(int messageId, string context) {

    messageId -= 1;

    auto tmpPeople = PeopleDao::selectOnePeople(Storage::getSUserId());


    Storage::messageArray[messageId]->setTutorId(Storage::getSUserId());
    Storage::messageArray[messageId]->setTutorComment(context);
    Storage::messageArray[messageId]->setTutorName(tmpPeople->getName());

    delete tmpPeople;

    // cout << *Storage::messageArray[messageId] << endl;

}
