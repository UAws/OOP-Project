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

