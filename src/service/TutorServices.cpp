// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 24/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include <service/include/SERVICE_PUBLIC.h>
#include <vo/include/VO_PUBLIC.h>


bool TutorServices::changeUserName(int user_id, string user_name) {
    return PeopleServices::changeUserName(user_id, user_name);
}

bool TutorServices::addNewStudent(Student *people) {
    return PeopleServices::addNewStudent(people);
}

void TutorServices::showStudents() {
    PeopleServices::showStudents();
}

void TutorServices::showSubjects() {
    PeopleServices::showSubjects();
}

bool TutorServices::showSubjectsEnrolledById(int user_id) {
    return PeopleServices::showSubjectsEnrolledById(user_id);
}
