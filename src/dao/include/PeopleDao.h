// Author : Akide Liu 
// Date : 25/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef OOP_PROJECT_PEOPLEDAO_H
#define OOP_PROJECT_PEOPLEDAO_H

#include <vo/include/VO_PUBLIC.h>

class PeopleDao {
public:

    // list
    static vector<People *> listAllUsers();

    static vector<People *> showAllStudents();

    static vector<People *> showAllTutors();

    static vector<People *> showAllTeachers();


    // select

    static People *selectOnePeople(int id);

    static vector<People *> selectPeopleByName(string name);

    static pair<People *, vector<Subject *>> selectSubjectPeopleEnrolledByUserId(int id);



    //insert

    static bool addNewStudent(Student *student);

    static bool addNewTutor(Tutor *tutor);

    static bool addNewTeacher(Teacher *teacher);


    //update

    static bool updatePeopleName(int id, string name);

    static bool updatePeoplePassword(int id, string password);

    static bool updatePeopleResetPassword(int id);

    static bool updatePeopleActive(int id, bool flag);



};


#endif //OOP_PROJECT_PEOPLEDAO_H
