// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 24/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef OOP_PROJECT_PEOPLESERVICESH_
#define OOP_PROJECT_PEOPLESERVICESH_

#include <iostream>
#include <vector>
#include <algorithm>

#include <prettyprint.hpp>
#include <vo/include/People.h>

class PeopleServices {

public:
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


private:

    static int s_user_id;

    static int s_subject_id;

    static PeopleServices * currentUser;

public:
    static void setCurrentUser(PeopleServices *&currentUser);

public:
    static PeopleServices * getCurrentUser();

};


#endif //OOP_PROJECT_PEOPLESERVICESH_
