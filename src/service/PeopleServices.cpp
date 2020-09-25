// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 24/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include <service/include/SERVICE_PUBLIC.h>
#include <vo/include/VO_PUBLIC.h>

bool PeopleServices::login(int user_id , string password) {

    /*
     * try find user_id from storage people array
     * if found , assign global static variable to current user by user id
     */

    //TODO: need to replace by database
    if (Storage::storagePeople[user_id] != nullptr ) {
        Storage::setCurrentUserById(user_id);
    } else {
        cout << "user_id not found : " << user_id << endl;
        return false;
    }

    /*
     * check current user is active(not locked) or not.
     */
    //TODO: need to replace by database
    if (!Storage::getCurrentUser()->isActive1()){
        cout << "Hi," << Storage::getCurrentUser()->getName() << "your acount is locked , please contact your tutor or teacher for unlock" << endl;
        return false;
    }

    /*
     * if password equals to default password '-1', then execute initialization of current user 's password
     */
    //TODO: need to replace by database
    if(password == "-1" && password == Storage::getCurrentUser()->getPassword()){

        /*
         * initpassword function will return the results of password initialization
         */
        return initPassword();

        /*
         * check input password as same as the password stored inside storage.
         */
        //TODO: need to replace by database
    }else if ( password == Storage::getCurrentUser()->getPassword()){

        return true;

    }

    /* login failed
     * unknown conditions default return false.
     */
    return false;
}

bool PeopleServices::logout(int user_id) {
    // Storage::setCurrentUser(People());

    //TODO: need to replace by database
    cout << Storage::getCurrentUser()->getName() << "Log out successfully !" << std::endl;
    return true;
}

bool PeopleServices::initPassword() {

    /*
     * this function will be called only if current user's id equals to "-1" (the default password)
     * this function try to request user's input as maximum 3 times
     * if failed to enter same password over maximum 3 times , the current user will be locked (can not login )
     * after pass all required check, password will be modified and updated to storage
     */

    string password,secondPasswd;
    int count = 3;
    while (true) {
        //TODO: need to replace by database
        cout << "Please enter your password for user " << Storage::getCurrentUser()->getName() << ":" << std::endl;
        cin >> password;
        cout << "Please re-enter your password : ";
        cin >> secondPasswd;

        if (password == secondPasswd) {
            break;
        } else {
            if (count >= 1){
                cout << "your entered passwords are not same, plz try again ; you have " << count << "chance left ." << endl;
                count--;
            } else {
                //TODO: need to replace by database
                cout << "Hi," << Storage::getCurrentUser()->getName() << "your acount is locked , please contact your tutor or teacher for unlock" << endl;
                lockUser(Storage::getCurrentUser()->getUserId());
                break;
            }
        }
    }

    //TODO: need to replace by database
    Storage::getCurrentUser()->setPassword(password);
    return true;
}

bool PeopleServices::changePassword(int user_id, const string &oldPassword, const string &new_password) {

    if (oldPassword != new_password) {
        //TODO: need to replace by database
        Storage::getCurrentUser()->setPassword(new_password);
        return true;
    }
    return false;
}

void PeopleServices::ListAllUsers() {
    //TODO: need to replace by database
    for (const auto& kv : Storage::storagePeople) {
        std::cout << kv.first << " has value " << *kv.second <<" userLevel : "<<kv.second->getUserLevel()<<std::endl;
    }
}


void PeopleServices::addNewTutor(People people) {

}

void PeopleServices::modifyTutorById(int user_id) {

}

void PeopleServices::addNewStudent(People *people) {

}

void PeopleServices::modifyStudentById(int user_id) {

}

void PeopleServices::addNewSubject(Subject subject) {

}

void PeopleServices::modifySubjectById(int subject_id) {

}

void PeopleServices::showStudents() {

}

void PeopleServices::showTutors() {

}

void PeopleServices::showSubjects() {

}

int PeopleServices::checkUserLevelById(int user_id) {
    //TODO: need to replace by database
    return Storage::getCurrentUser()->getUserLevel();
}

void PeopleServices::resetUserPasswordById(int user_id) {
    unlockUser(user_id);
    //TODO: need to replace by database
    Storage::getCurrentUser()->setPassword("-1");
}



void PeopleServices::unlockUser(int user_id) {
    //TODO: need to replace by database
    Storage::storagePeople[user_id]->setIsActive(true);
}

void PeopleServices::lockUser(int user_id) {
    //TODO: need to replace by database
    Storage::storagePeople[user_id]->setIsActive(false);
}


PeopleServices * PeopleServices::getCurrentUser() {
    return currentUser;
}

PeopleServices * PeopleServices::currentUser = nullptr;
