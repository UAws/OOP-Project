// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "include/VO_PUBLIC.h"
#include "include/People.h"


People::People(const string &name, const string &title) : name(name), title(title) {}

People::People() {};


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
}

ostream &operator<<(ostream &os, const People &people) {

    os << "user_id: " << people.user_id << " name: " << people.name << " password: " << people.password << " title: "
       << people.title << " isActive: " << people.isActive ;
    return os;
}

int People::getUserLevel() const {
    return 0;
}

void People::setUserLevel(int userLevel) {

}

People::~People() {

}

