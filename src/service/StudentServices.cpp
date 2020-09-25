// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 24/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include <service/include/SERVICE_PUBLIC.h>
#include <vo/include/VO_PUBLIC.h>

void StudentServices::showSubjects() {

        VariadicTable<int, string, string> vt({"Subject ID", "Subject name", "Enrollment"});

    //TODO: need to replace by database
        for (const auto& kv : Storage::storageSubjects) {

            vector<int> tmp = kv.second.getUserIdEnrolled();

            /*
             * find an element in vector
             * reference :
             * https://thispointer.com/c-how-to-find-an-element-in-vector-and-get-its-index/
             */
            auto it = find(tmp.begin(), tmp.end(),
                    //TODO: need to replace by database
                           Storage::getCurrentUser()->getUserId());
            if (it != tmp.end()) {
                vt.addRow(kv.second.getSubjectId(), kv.second.getSubjectName(), "enrolled");
            } else {
                vt.addRow(kv.second.getSubjectId(), kv.second.getSubjectName(), "unrolled");
            }
        }

        vt.print(std::cout);

}
