// Author : Akide Liu 
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef CPP_PEOPLE_H
#define CPP_PEOPLE_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "../../utils/prettyprint.hpp"
#include "Subject.h"

using namespace std;

class People {
public:
    /*
     * constructor and destructor
     */
    People();

    People(int userId, const string &name, const string &password, const string &title, bool isActive);

    People(const string &name, const string &title);

    virtual ~People();

    /*
     * static utils functions
     */

    static bool logout(int user_id);

    static bool login(int user_id, string password);

    static bool initPassword();

    static bool changePassword(int user_id, const string &oldPassword , const string &new_password);

    static void ListAllUsers();

    static int checkUserLevelById(int user_id);

    static void resetUserPasswordById(int user_id);

    static void lockUser(int user_id);

    static void unlockUser(int user_id);

    /*
     * object getter and setter
     */

    virtual int getUserId() const;

    virtual void setUserId(int userId);

    virtual const string &getName() const;

    virtual void setName(const string &name);

    virtual const string &getPassword() const;

    virtual void setPassword(const string &password);

    virtual const string &getTitle() const;

    virtual void setTitle(const string &title);

    virtual bool isActive1() const;

    virtual void setIsActive(bool isActive);

    virtual int getUserLevel() const;

    virtual void setUserLevel(int userLevel);

    friend ostream &operator<<(ostream &os, const People &people);

    /*
     * userAction functions
     */

    virtual void addNewTutor(People people);

    virtual void modifyTutorById(int user_id);

    virtual void addNewStudent(People *people);

    virtual void modifyStudentById(int user_id);

    virtual void addNewSubject(Subject subject);

    virtual void modifySubjectById(int subject_id);

    virtual void showStudents();

    virtual void showTutors();

    virtual void showSubjects();

    virtual vector<int> getUserSubjectId();




protected:
        /* level : 1 --> student
         * level : 2 --> tutor
         * level : 3 --> teacher    */

    int userLevel;
    int user_id;
    string name;
    string password = "-1";
    string title;
    bool isActive;
    vector<int> userSubjectId;

};


#endif //CPP_PEOPLE_H
