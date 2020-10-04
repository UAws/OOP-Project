// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 24/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include <service/include/SERVICE_PUBLIC.h>
#include <vo/include/VO_PUBLIC.h>


void StudentServices::showSubjects() {
    PeopleServices::showSubjects();
}

bool StudentServices::showSubjectsEnrolledById(int user_id) {
    return PeopleServices::showSubjectsEnrolledById(user_id);
}
