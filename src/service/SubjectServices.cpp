// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 24/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include <service/include/SERVICE_PUBLIC.h>
#include <vo/include/VO_PUBLIC.h>
#include <service/include/SubjectServices.h>
#include <dao/include/SubjectDao.h>



void SubjectServices::listAllSubjects() {

    vector<Subject *> subj = SubjectDao::listAllSubjects();

    VariadicTable<int, std::string> vt ({"SubjectID", "SubjectName"});

    for (auto & i : subj) {
        vt.addRow(i->getSubjectId(), i->getSubjectName());
    }

    vt.print(cout);

}

void SubjectServices::displayOneSubject(int id) {

    Subject *subject = SubjectDao::selectOneSubject(id);

    if (subject != nullptr) {
        VariadicTable<int, std::string> vt({"SubjectID", "SubjectName"});

        vt.addRow(subject->getSubjectId(), subject->getSubjectName());

        vt.print(cout);
    } else {
        cerr << "The subject ID : " << id << " not found" << endl;
    }

    delete subject;

}

void SubjectServices::displaySubjectByName(const string name) {

    vector<Subject *> subjects = SubjectDao::selectSubjectByName(name);

    if (!subjects.empty()) {
        VariadicTable<int, std::string> vt({"SubjectID", "SubjectName"});

        for (auto & i : subjects) {
            vt.addRow(i->getSubjectId(), i->getSubjectName());
        }

        vt.print(cout);
    } else {
        cerr << "The subject name : " << name << " not found" << endl;

    }

}

bool SubjectServices::addNewSubject(string name) {

    bool flag = SubjectDao::addNewSubject(new Subject(0, name));

    if (flag) {

        cout << "The subject added successfully " << name << endl;

        SubjectServices::displaySubjectByName(name);

        return true;

    } else {

        return false;

    }

}

bool SubjectServices::addStudentToSubject(int userId, int subjectId) {
    return false;
}
