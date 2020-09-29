// Author : Akide Liu 
// Date : 25/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef OOP_PROJECT_SUBJECTDAO_H
#define OOP_PROJECT_SUBJECTDAO_H

#include <vo/include/VO_PUBLIC.h>

class SubjectDao {
public:
    // list

    static vector<Subject*> listAllSubjects();

    // select

    static Subject* selectOneSubject(int id);

    static vector<Subject*> selectSubjectByName(string name);

    //insert

    static bool addNewSubject(Subject *subject);

    //update

    static bool updatePeopleToSubject(int userId, int subjectId);


};


#endif //OOP_PROJECT_SUBJECTDAO_H
