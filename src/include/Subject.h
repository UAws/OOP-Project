// Author : Akide Liu 
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef CPP_SUBJECT_H
#define CPP_SUBJECT_H
#include <iostream>
#include <vector>

using namespace std;

class Subject {
private:
    int subject_id;
    string subject_name;
    vector<int> userIdEnrolled;

public:

    Subject(int subjectId, const string &subjectName);

    int getSubjectId() const;

    void setSubjectId(int subjectId);

    const string &getSubjectName() const;

    void setSubjectName(const string &subjectName);

    vector<int> getUserIdEnrolled() const;

    void setUserIdEnrolled(const vector<int> &userIdEnrolled);

    void addUserIdEnrolledById(int id);

    friend ostream &operator<<(ostream &os, const Subject &subject);

};


#endif //CPP_SUBJECT_H
