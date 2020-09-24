// Author : Akide Liu 
// Date : 24/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef OOP_PROJECT_TUTORSERVICES_H
#define OOP_PROJECT_TUTORSERVICES_H

#include "PeopleServices.h"

class TutorServices : public PeopleServices{

public:
    void showStudents() override;

    void addNewStudent(People *people) override;

    void modifyStudentById(int user_id) override;
};


#endif //OOP_PROJECT_TUTORSERVICES_H
