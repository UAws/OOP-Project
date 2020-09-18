// Author : Akide Liu
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "include/PUBLIC.h"
#include "include/People.h"


People::People(const string &name, const string &title) : name(name), title(title) {}

People::People() {};

bool People::login(int user_id , string password) {

    /*
     * try find user_id from storage people array
     * if found , assign global static variable to current user by user id
     */
    if (Storage::storagePeople[user_id] != nullptr ) {
       Storage::setCurrentUserById(user_id);
    } else {
        cout << "user_id not found : " << user_id << endl;
        return false;
    }

    /*
     * check current user is active(not locked) or not.
     */
    if (!Storage::getCurrentUser()->isActive1()){
        cout << "Hi," << Storage::getCurrentUser()->getName() << "your acount is locked , please contact your tutor or teacher for unlock" << endl;
        return false;
    }

    /*
     * if password equals to default password '-1', then execute initialization of current user 's password
     */
    if(password == "-1" && password == Storage::getCurrentUser()->getPassword()){

        /*
         * initpassword function will return the results of password initialization
         */
        return initPassword();

    /*
     * check input password as same as the password stored inside storage.
     */
    }else if ( password == Storage::getCurrentUser()->getPassword()){

        return true;

    }

    /* login failed
     * unknown conditions default return false.
     */
    return false;
}

bool People::logout(int user_id) {
    // Storage::setCurrentUser(People());

    cout << Storage::getCurrentUser()->getName() << "Log out successfully !" << std::endl;
    return true;
}

bool People::initPassword() {

    /*
     * this function will be called only if current user's id equals to "-1" (the default password)
     * this function try to request user's input as maximum 3 times
     * if failed to enter same password over maximum 3 times , the current user will be locked (can not login )
     * after pass all required check, password will be modified and updated to storage
     */

    string password,secondPasswd;
    int count = 3;
    while (true) {
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
                cout << "Hi," << Storage::getCurrentUser()->getName() << "your acount is locked , please contact your tutor or teacher for unlock" << endl;
                lockUser(Storage::getCurrentUser()->getUserId());
                break;
            }
        }
    }

    Storage::getCurrentUser()->setPassword(password);
    return true;
}

bool People::changePassword(int user_id, const string &oldPassword, const string &new_password) {

    if (oldPassword != new_password) {
        Storage::getCurrentUser()->setPassword(new_password);
        return true;
    }
    return false;
}

void People::ListAllUsers() {
    for (const auto& kv : Storage::storagePeople) {
        std::cout << kv.first << " has value " << *kv.second <<" userLevel : "<<kv.second->getUserLevel()<<std::endl;
    }
}

int People::getUserId() const {
    return user_id;
}

void People::setUserId(int userId) {
    user_id = userId;
}

const string &People::getName() const {
    return name;
}

void People::setName(const string &name) {
    People::name = name;
}

const string &People::getPassword() const {
    return password;
}

void People::setPassword(const string &password) {
    People::password = password;
}

const string &People::getTitle() const {
    return title;
}

void People::setTitle(const string &title) {
    People::title = title;
}

bool People::isActive1() const {
    return isActive;
}

void People::setIsActive(bool isActive) {
    People::isActive = isActive;
}

People::People(int userId, const string &name, const string &password, const string &title, bool isActive) : user_id(userId), name(name) , password(password),title(title) ,isActive(isActive){
    Storage::setSUserId(Storage::getSUserId() + 1);
}

ostream &operator<<(ostream &os, const People &people) {

    os << "user_id: " << people.user_id << " name: " << people.name << " password: " << people.password << " title: "
       << people.title << " isActive: " << people.isActive << " getUserSubjectId: " << people.userSubjectId;
    return os;
}

void People::addNewTutor(People people) {

}

void People::modifyTutorById(int user_id) {

}

int People::getUserLevel() const {
    return 0;
}

void People::setUserLevel(int userLevel) {

}

void People::addNewStudent(People *people) {

}

void People::modifyStudentById(int user_id) {

}

void People::addNewSubject(Subject subject) {

}

void People::modifySubjectById(int subject_id) {

}

void People::showStudents() {

}

void People::showTutors() {

}

void People::showSubjects() {

}

int People::checkUserLevelById(int user_id) {
    return Storage::getCurrentUser()->getUserLevel();
}

void People::resetUserPasswordById(int user_id) {
    unlockUser(user_id);
    Storage::getCurrentUser()->setPassword("-1");
}

People::~People() {

}

void People::unlockUser(int user_id) {
    Storage::storagePeople[user_id]->setIsActive(true);
}

void People::lockUser(int user_id) {
    Storage::storagePeople[user_id]->setIsActive(false);
}

vector<int> People::getUserSubjectId() {
    vector<int> result;
    for (const auto& kv : Storage::storageSubjects) {

        vector<int> tmp = kv.second.getUserIdEnrolled();

        auto it = find(tmp.begin(), tmp.end(),
                       this->getUserId());
        if (it != tmp.end()) {
            result.push_back(kv.first);
        }
    }
    return vector<int>();
}
