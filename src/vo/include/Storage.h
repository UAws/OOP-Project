// Author : Akide Liu 
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef CPP_STORAGE_H
#define CPP_STORAGE_H

#include <iostream>
#include <vector>
#include <map>
#include "People.h"

//TODO: need to replace by database
using namespace std;

class Storage {

public:
    static void clearHeap();

    static map<int,People *> storagePeople;

    static map<int,Subject> storageSubjects;

    static int useUser_Id();

    static int useSubject_Id();

    static vector<string> title_array;

    static int getSUserId();

    static void setSUserId(int sUserId);

    static int getSSubjectId();

    static void setSSubjectId(int sSubjectId);

    static void setCurrentUserById(int i);

private:

    static int s_user_id;

    static int s_subject_id;

    static People * currentUser;

public:
    static void setCurrentUser(People *&currentUser);

public:
    static People * getCurrentUser();
};


#endif //CPP_STORAGE_H
