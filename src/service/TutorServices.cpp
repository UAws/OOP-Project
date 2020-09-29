// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 24/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include <service/include/SERVICE_PUBLIC.h>
#include <vo/include/VO_PUBLIC.h>


void TutorServices::showStudents() {
    VariadicTable<int, string, string, bool> vt({"Student ID", "Student name", "Title", "IsActive"});

    //TODO: need to replace by database
    // for (const auto& kv : Storage::storagePeople) {
    //     if (kv.second->getUserLevel() == 1) {
    //         People stu = *kv.second;
    //         vt.addRow(stu.getUserId(), stu.getName(), stu.getTitle(),stu.isActive1());
    //     }
    // }

    // vt.print(cout);
}
//chi has changed the "void" to "bool" for not sure.
bool TutorServices::addNewStudent(Student *people) {
    //TODO: need to replace by database
    // Storage::storagePeople.insert(std::make_pair(people->getUserId(), people));
}

void TutorServices::modifyStudentById(int user_id) {
    PeopleServices::modifyStudentById(user_id);
}
