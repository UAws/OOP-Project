// Author : Akide Liu 
// Date : 13/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "include/VO_PUBLIC.h"

int Subject::getSubjectId() const {
    return subject_id;
}

void Subject::setSubjectId(int subjectId) {
    subject_id = subjectId;
}

const string &Subject::getSubjectName() const {
    return subject_name;
}

void Subject::setSubjectName(const string &subjectName) {
    subject_name = subjectName;
}

vector<int> Subject::getUserIdEnrolled() const {
    return userIdEnrolled;
}

void Subject::setUserIdEnrolled(const vector<int> &userIdEnrolled) {
    Subject::userIdEnrolled = userIdEnrolled;
}

Subject::Subject(int subjectId, const string &subjectName) : subject_id(subjectId), subject_name(subjectName){

    //TODO: need to replace by database
    Storage::setSSubjectId(Storage::getSSubjectId() + 1);

    /*
     * auto enroll teacher and tutor to all subject
     *
     */

    //TODO: need to replace by database
    for (const auto& kv : Storage::storagePeople) {
        if (kv.second->getUserLevel() == 2 || kv.second->getUserLevel() == 3) {
            this->addUserIdEnrolledById(kv.first);
        }
    }

}

void Subject::addUserIdEnrolledById(int id) {

    /*
     * check does current subject contains id from parameter or not
     */

        int count = 0;
        for (size_t i = 0; i < userIdEnrolled.size(); ++i) {
            if (id != i){
                count++;
            }
        }
        if (count == userIdEnrolled.size()) {
            this->userIdEnrolled.push_back(id);
        }
}

ostream &operator<<(ostream &os, const Subject &subject) {
    os << "subject_id: " << subject.subject_id << " subject_name: " << subject.subject_name << " userIdEnrolled: "
       << subject.userIdEnrolled;
    return os;
}
