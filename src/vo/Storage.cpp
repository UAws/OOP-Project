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


int Storage::s_user_id = 1;

int Storage::s_subject_id = 1;

int Storage::messageID = 1;

vector<Message *> Storage::messageArray;

int Storage::getSUserId() {
    return s_user_id;
}

void Storage::setSUserId(int sUserId) {
    s_user_id = sUserId;
}

int Storage::getSSubjectId() {
    return s_subject_id;
}

void Storage::setSSubjectId(int sSubjectId) {
    s_subject_id = sSubjectId;
}





