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
#include <dao/include/SubjectDao.h>


void StudentServices::showSubjects() {
    PeopleServices::showSubjects();
}

bool StudentServices::showSubjectsEnrolledById(int user_id) {
    return PeopleServices::showSubjectsEnrolledById(user_id);
}

void StudentServices::communicate(int id, string context) {

    //id is subject id;
    const int subject_id = id;

    auto tmpMessage = new Message(Storage::messageID, Storage::getSUserId(), subject_id);

    auto tmpPeople = PeopleDao::selectOnePeople(Storage::getSUserId());

    auto tmpSubject = SubjectDao::selectOneSubject(id);

    tmpMessage->setStudentName(tmpPeople->getName());

    tmpMessage->setSubjectName(tmpSubject->getSubjectName());

    Storage::messageArray.push_back(tmpMessage);

    Storage::messageID += 1;

    delete tmpPeople;

    delete tmpSubject;

}
