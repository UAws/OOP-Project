/*

Authors: Akide Liu ; Andrew Wang ; Chi Wang
Date : 24/9/20

OOP-Project
Copyright (C) <2020>  Akide Liu ; Andrew Wang ; Chi Wang

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

Description :

*/

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
