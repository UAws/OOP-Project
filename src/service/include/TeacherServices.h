// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 24/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef OOP_PROJECT_TEACHERSERVICES_H
#define OOP_PROJECT_TEACHERSERVICES_H

#include "PeopleServices.h"

class TeacherServices : public PeopleServices {

public:
    bool addNewTutor(Tutor *people) override;

    bool changeUserName(int user_id, string user_name) override;

    bool addNewStudent(Student *people) override;

    bool addNewSubject(Subject *subject) override;

    bool changeSubjectName(int subject_id, string subject_name) override;

    void showStudents() override;

    void showTutors() override;

    void showSubjects() override;

    bool showSubjectsEnrolledById(int user_id) override;

};


#endif //OOP_PROJECT_TEACHERSERVICES_H
