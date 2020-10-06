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

#include "include/VO_PUBLIC.h"

int Subject::getSubjectId() const {
    return subject_id;
}

void Subject::setSubjectId(int subjectId) {
    subject_id = subjectId;
}

const string &Subject::getSubjectName() const {
    return subject_name;
}

void Subject::setSubjectName(const string &subjectName) {
    subject_name = subjectName;
}

Subject::Subject(int subjectId, const string &subjectName) : subject_id(subjectId), subject_name(subjectName){

    //TODO: need to replace by database
    // Storage::setSSubjectId(Storage::getSSubjectId() + 1);

    /*
     * auto enroll teacher and tutor to all subject
     *
     */

    //TODO: need to replace by database
    // for (const auto& kv : Storage::storagePeople) {
    //     if (kv.second->getUserLevel() == 2 || kv.second->getUserLevel() == 3) {
    //         this->addUserIdEnrolledById(kv.first);
    //     }
    // }

}

ostream &operator<<(ostream &os, const Subject &subject) {
    os << "subject_id: " << subject.subject_id << " subject_name: " << subject.subject_name;
    return os;
}
