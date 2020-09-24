// Author : Akide Liu 
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "include/VO_PUBLIC.h"

//TODO: need to replace by database

void Storage::setCurrentUserById(int i){

    Storage::currentUser = Storage::storagePeople[i];

}

int Storage::s_user_id = 1;

 int Storage::s_subject_id = 1;

 vector<string> Storage::title_array {"","student","tutor","teacher"};

 map<int,People*> Storage::storagePeople {
        {Storage::getSUserId(),new Student(Storage::getSUserId(),"student01")},
        {Storage::getSUserId(),new Tutor(Storage::getSUserId(),"tutor01")},
        {Storage::getSUserId(),new Teacher(Storage::getSUserId(),"teacher01")}
};

map<int, Subject> Storage::storageSubjects{
        {Storage::getSSubjectId(), Subject(Storage::getSSubjectId(), "Subject01")},
        {Storage::getSSubjectId(), Subject(Storage::getSSubjectId(), "Subject02")}
};

int Storage::useUser_Id() {
    Storage::s_user_id += 1;
    return Storage::s_user_id - 1;
}

int Storage::useSubject_Id() {
    Storage::s_subject_id += 1;
    return Storage::s_subject_id - 1;
}

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

void Storage::clearHeap() {
    for (const auto& kv : Storage::storagePeople) {
        delete kv.second;
    }

}

People * Storage::getCurrentUser() {
    return currentUser;
}

People * Storage::currentUser = nullptr;



