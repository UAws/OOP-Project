// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "include/VO_PUBLIC.h"


int Storage::s_user_id = 1;

 int Storage::s_subject_id = 1;


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





