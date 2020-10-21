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
#include <service/include/PeopleServices.h>


bool PeopleServices::login(int user_id , string password) {

/*
     * try find user_id from database
     * if found , assign global static variable to current user by user id
     * put current user info into storage
     */

    People* People = PeopleDao::selectOnePeople(user_id);
    if (People != nullptr ) {
        Storage::setSUserId(user_id);
    } else {
        cout << "user_id not found : " << user_id << endl;
        delete People;
        return false;
    }

/*
     * check current user is active(not locked) or not.
     */

     if (!People->isActive1()){
        cout << "Hi," << People->getName() << "your acount is locked , please contact your tutor or teacher for unlock" << endl;
        delete People;
         exit(2);
        return false;
    }

    /*
     * if password equals to default password '-1', then execute initialization of current user 's password
     */
    if(password == "-1" && password == People->getPassword()){

        delete People;
        return initPassword();

         /*
         * check input password as same as the password stored inside storage.
         */
    }else if (password == People->getPassword()){
        delete People;
        return true;
    }


    /* login failed
     * unknown conditions default return false.
     */


    cout << "password for " << People->getName() << " not correct  , you may try default '-1' " << endl;

    delete People;

    return false;
}

bool PeopleServices::logout(int user_id) {
    // Storage::setCurrentUser(People());

    People* people = PeopleDao::selectOnePeople(user_id);
    if(people != nullptr){
        cout << people->getName() << "Log out successfully !" << std::endl;
        Storage::setSUserId(-1);// satic variable(currentUserId) from storage need to be reset to -1
        delete people;
        return true;
    }else{
        cout <<"The user ID: "<< user_id << "does not exist. "<< endl;
        delete people;
        return false;
    }
   

}

bool PeopleServices::initPassword() {

    /*
     * this function will be called only if current user's id equals to "-1" (the default password)
     * this function try to request user's input as maximum 3 times
     * if failed to enter same password over maximum 3 times , the current user will be locked (can not login )
     * after pass all required check, password will be modified and updated to storage
     */
    
    People* People = PeopleDao::selectOnePeople(Storage::getSUserId());

    string password,secondPasswd;
    int count = 3;
    while (true) {
        cout << "Please reset your password for user " << People->getName() << ":" << std::endl;
        cin >> password;
        cout << "Please re-enter your password : " << endl;
        cin >> secondPasswd;

        if (password == secondPasswd) {
            break;
        } else {
            if (count >= 1){
                cout << "password you entered is not the same, please try again ; you have " << count << " chance left ." << endl;
                count--;
            } else {
                cout << "Hi," << People->getName() << "your account is locked , please contact your tutor or teacher for unlock" << endl;
                lockUser(People->getUserId());
                delete People;
                return false;
            }
        }
    }

    // People->setPassword(password);
    // PeopleDao curUser;
    // curUser.updatePeoplePassword(People->getUserId(), People->getName());
    PeopleDao::updatePeoplePassword(People->getUserId(), password);
    delete People;
    return true;
}

bool PeopleServices::changePassword(int user_id, const string password) {

    People* People = PeopleDao::selectOnePeople(user_id);

    // if (oldPassword != new_password) {
        
        if (password != People->getPassword()) {

        // People->setPassword(new_password);

        delete People;
        return PeopleDao::updatePeoplePassword(user_id, password);
    }

    delete People;
    return false;
}

void PeopleServices::ListAllUsers() {

    vector<People *> People = PeopleDao::listAllUsers();


    VariadicTable<int, string, string, bool> vt({"People ID", "People name", "Title", "IsActive"});
    for (size_t i = 0; i < People.size(); ++i) {

        vt.addRow(People[i]->getUserId(), People[i]->getName(), People[i]->getTitle(),People[i]->isActive1());
    }
    vt.print(cout);
}

//Chi completed
bool PeopleServices::addNewTutor(Tutor *people) {
    return PeopleDao::addNewTutor(people);

}

bool PeopleServices::changeUserName(int user_id, string user_name) {

    auto p = PeopleDao::selectOnePeople(user_id);
    if (p == nullptr) {
        cout << "user_id not found : " << user_id << endl;
        delete p;
        return false;
    }

    if (PeopleDao::updatePeopleName(user_id, user_name)) {

        cout << "user information updated : " << user_name << endl;
    }

    return true;

}
//Chi completed
bool PeopleServices::addNewStudent(Student *people) {
    return PeopleDao::addNewStudent(people);
}

//Chi
bool PeopleServices::addNewSubject(Subject *subject) {
    return SubjectDao::addNewSubject(subject);
}

bool PeopleServices::changeSubjectName(int subject_id, string subject_name) {
    auto p = SubjectDao::selectOneSubject(subject_id);
    if (p == nullptr) {
        cout << "subject_id not found : " << subject_id << endl;
        delete p;
        return false;
    }
    if (SubjectDao::updateSubjectName(subject_id, subject_name)) {

        cout << "subject information updated : " << subject_name << endl;
    }

    return true;

}

void PeopleServices::showStudents() {
    
    vector<People *> Student = PeopleDao::showAllStudents();

    VariadicTable<int, string, bool> vt({"Student ID", "Student name", "IsActive"});
    for (auto & i : Student) {

        vt.addRow(i->getUserId(), i->getName(), i->isActive1());
    }
    vt.print(cout);
}

void PeopleServices::showTutors() {
    vector<People *> Tutor = PeopleDao::showAllTutors();

    VariadicTable<int, string, bool> vt({"Tutor ID", "Tutor name", "IsActive"});
    for (auto & i : Tutor) {

        vt.addRow(i->getUserId(), i->getName(), i->isActive1());
    }
    vt.print(cout);

}

void PeopleServices::showSubjects() {
    vector<Subject *> Subject = SubjectDao::listAllSubjects();

    VariadicTable<int, string> vt({"Subject ID", "Subject name"});
    for (auto & i : Subject) {

        vt.addRow(i->getSubjectId(), i->getSubjectName());
    }
    vt.print(cout);


}

int PeopleServices::checkUserLevelById(int user_id) {

    People *p = PeopleDao::selectOnePeople(user_id);

    if (p == nullptr) {
        delete p;
        return 0;
    }

    int level = p->getUserLevel();
    delete p;

    return level;

}
//Chi completed
bool PeopleServices::resetUserPasswordById(int user_id) {

    return PeopleDao::updatePeopleResetPassword(user_id);
   
}


//Chi completed
bool PeopleServices::unlockUser(int user_id) {

    return PeopleDao::updatePeopleActive(user_id, true);

}
//Chi completed
bool PeopleServices::lockUser(int user_id) {

    return PeopleDao::updatePeopleActive(user_id, false);

}

PeopleServices::~PeopleServices() = default;

bool PeopleServices::showSubjectsEnrolledById(int user_id){
    auto result = PeopleDao::selectSubjectPeopleEnrolledByUserId(user_id);

    if (result.first == nullptr) {
        cerr << "PeopleServices error : user_id : " << user_id << " not found" << endl;
        return false;
    }

    VariadicTable<string, string, int, string> vc({"Student ID", "Student Name", "Subject ID", "Subject name"});

    bool flag = true;
    for (auto & i : result.second) {
        if (flag) {
            vc.addRow(to_string(result.first->getUserId()), result.first->getName(),i->getSubjectId(), i->getSubjectName());
            flag = false;
        } else {
            vc.addRow("","",i->getSubjectId(), i->getSubjectName());
        }
    }

    vc.print(cout);

    return true;


}

void PeopleServices::showCommunication() {

    VariadicTable<int, int, string, string, string, string, string> vc(
            {"messageID", "studentID", "studentName", "subjectName", "tutorName", "tutorComment", "approve?"});

    for (auto & i : Storage::messageArray) {
        vc.addRow(i->getMessageId(),
                  i->getStudentId(),
                  i->getStudentName(),
                  i->getSubjectName(),
                  i->getTutorName(),
                  i->getTutorComment(),
                  i->getApprove());
    }

    vc.print(cout);

}

