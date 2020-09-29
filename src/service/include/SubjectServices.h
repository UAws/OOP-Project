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

    vector<int> getUserIdEnrolled() const;

    void setUserIdEnrolled(const vector<int> &userIdEnrolled);

    void addUserIdEnrolledById(int id);

private:
    //TODO: need to replace by database
    vector<int> userIdEnrolled;





};


#endif //OOP_PROJECT_SUBJECTSERVICES_H
