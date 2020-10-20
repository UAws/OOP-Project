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

#ifndef OOP_PROJECT_STUDENTSERVICES_H
#define OOP_PROJECT_STUDENTSERVICES_H


#include "PeopleServices.h"
#include "PeopleCommunications.h"

class StudentServices : public PeopleServices,public PeopleCommunications {

public:
    void showSubjects() override;

    bool showSubjectsEnrolledById(int user_id) override;

    void communicate(int id, string context) override;

};


#endif //OOP_PROJECT_STUDENTSERVICES_H
