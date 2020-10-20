// Author : Akide Liu 
// Date : 20/10/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef OOP_PROJECT_PEOPLECOMMUNICATIONS_H
#define OOP_PROJECT_PEOPLECOMMUNICATIONS_H

#include <iostream>
#include <vector>
#include <algorithm>

#include <prettyprint.hpp>
#include <vo/include/People.h>
#include <vo/include/VO_PUBLIC.h>

class PeopleCommunications {
protected:
    virtual void communicate(int id, string context) = 0;
};


#endif //OOP_PROJECT_PEOPLECOMMUNICATIONS_H
