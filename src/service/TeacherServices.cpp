// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 24/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include <service/include/SERVICE_PUBLIC.h>
#include <vo/include/VO_PUBLIC.h>


bool TeacherServices::addNewTutor(Tutor *people) {
    return PeopleServices::addNewTutor(people);
}

bool TeacherServices::changeUserName(int user_id, string user_name) {
    return PeopleServices::changeUserName(user_id, user_name);
}

bool TeacherServices::addNewStudent(Student *people) {
    return PeopleServices::addNewStudent(people);
}

bool TeacherServices::addNewSubject(Subject *subject) {
    return PeopleServices::addNewSubject(subject);
}

bool TeacherServices::changeSubjectName(int subject_id, string subject_name) {
    return PeopleServices::changeSubjectName(subject_id, subject_name);
}

void TeacherServices::showStudents() {
    PeopleServices::showStudents();
}

void TeacherServices::showTutors() {
    PeopleServices::showTutors();
}

void TeacherServices::showSubjects() {
    PeopleServices::showSubjects();
}

bool TeacherServices::showSubjectsEnrolledById(int user_id) {
    return PeopleServices::showSubjectsEnrolledById(user_id);
}
