// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 24/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include <service/include/SERVICE_PUBLIC.h>
#include <vo/include/VO_PUBLIC.h>
#include <dao/include/PeopleDao.h>
#include <dao/include/SubjectDao.h>


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
        return false;
    }

/*
     * if password equals to default password '-1', then execute initialization of current user 's password
     */
    if(password == "-1" && password == People->getPassword()){

        delete People;
        return true;
        //TODO: need to take consider on testing
        // return initPassword();
         /*
         * check input password as same as the password stored inside storage.
         */
    }else if (password == People->getPassword()){
        delete People;
        return true;
    }

    delete People;

    /* login failed
     * unknown conditions default return false.
     */
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
        cout << "Please enter your password for user " << People->getName() << ":" << std::endl;
        cin >> password;
        cout << "Please re-enter your password : ";
        cin >> secondPasswd;

        if (password == secondPasswd) {
            break;
        } else {
            if (count >= 1){
                cout << "password you entered is not the same, please try again ; you have " << count << "chance left ." << endl;
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
    //TODO: need to replace by database
    // for (const auto& kv : Storage::storagePeople) {
    //     std::cout << kv.first << " has value " << *kv.second <<" userLevel : "<<kv.second->getUserLevel()<<std::endl;
    // }
    vector<People *> People = PeopleDao::listAllUsers();

    // for (size_t i = 0; i < People.size(); ++i) {
    //    cout << People[i] << " ";
    // }

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

void PeopleServices::modifyTutorById(int user_id) {

}
//Chi completed
bool PeopleServices::addNewStudent(Student *people) {
    return PeopleDao::addNewStudent(people);

}

void PeopleServices::modifyStudentById(int user_id) {
    // talk later
}
//Chi
bool PeopleServices::addNewSubject(Subject *subject) {
    return SubjectDao::addNewSubject(subject);
}

void PeopleServices::modifySubjectById(int subject_id) {
    // talk later
}

void PeopleServices::showStudents() {
    
    vector<People *> Student = PeopleDao::showAllStudents();

    VariadicTable<int, string, bool> vt({"Student ID", "Student name", "IsActive"});
    for (size_t i = 0; i < Student.size(); ++i) {

        vt.addRow(Student[i]->getUserId(), Student[i]->getName(), Student[i]->isActive1());
    }
    vt.print(cout);
}

void PeopleServices::showTutors() {
    vector<People *> Tutor = PeopleDao::showAllTutors();

    VariadicTable<int, string, bool> vt({"Tutor ID", "Tutor name", "IsActive"});
    for (size_t i = 0; i < Tutor.size(); ++i) {

        vt.addRow(Tutor[i]->getUserId(), Tutor[i]->getName(), Tutor[i]->isActive1());
    }
    vt.print(cout);

}

void PeopleServices::showSubjects() {
    vector<Subject *> Subject = SubjectDao::listAllSubjects();

    VariadicTable<int, string> vt({"Tutor ID", "Tutor name"});
    for (size_t i = 0; i < Subject.size(); ++i) {

        vt.addRow(Subject[i]->getSubjectId(), Subject[i]->getSubjectName());
    }
    vt.print(cout);


}

int PeopleServices::checkUserLevelById(int user_id) {
    //TODO: need to replace by database
    // return Storage::getCurrentUser()->getUserLevel();
    return 0;
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


PeopleServices * PeopleServices::getCurrentUser() {
    return currentUser;
}

PeopleServices * PeopleServices::currentUser = nullptr;
