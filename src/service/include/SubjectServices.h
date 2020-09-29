// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 24/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef OOP_PROJECT_SUBJECTSERVICES_H
#define OOP_PROJECT_SUBJECTSERVICES_H


class SubjectServices {
public:

    static void listAllSubjects();

    static void displayOneSubject(int id);

    static void displaySubjectByName(const string name);

    static bool addNewSubject(string name);

    static bool addStudentToSubject(int userId, int subjectId);



private:




};


#endif //OOP_PROJECT_SUBJECTSERVICES_H
