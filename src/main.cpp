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
#include <iostream>
#include <string>
#include <service/include/SERVICE_PUBLIC.h>
#include <vo/include/VO_PUBLIC.h>
#include <dao/include/PeopleDao.h>

using namespace std;

int input_Lim(int start, int end);

int init();

int teacherMenu(int ID);

int tutorMenu(int ID);

int studentMenu(int ID);

int main(int argc, char **argv) {

    initFlag:

    int ID = init();

// ----------------------------------------------------------------------------------------------------------------------------------
    if (PeopleServices::checkUserLevelById(ID) == 3) {

        int goBackFlag = teacherMenu(ID);

        while(goBackFlag == 0){
            goBackFlag = teacherMenu(ID);
        }
        if (goBackFlag == -1) {
            goto initFlag;
        }


    } else if (PeopleServices::checkUserLevelById(ID) == 2) {

        int goBackFlag = tutorMenu(ID);

        while(goBackFlag == 0){
            goBackFlag = tutorMenu(ID);
        }

        if (goBackFlag == -1) {
            goto initFlag;
        }


    } else if (PeopleServices::checkUserLevelById(ID) == 1) {

        int goBackFlag = studentMenu(ID);

        while(goBackFlag == 0){
            goBackFlag = studentMenu(ID);
        }

        if (goBackFlag == -1) {
            goto initFlag;
        }
    }
}



int input_Lim(int start, int end) {

    int inputNum;
    cout<<"";
    while(true){
        // https://stackoverflow.com/a/43845915/14207562

        if (cin >> inputNum && inputNum >= start && inputNum <= end){
            break;
        }
        else{
            cout<<"input error! Please enter again:";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return inputNum;
}

int init() {
    for (int i = 0; i < 9; i++) {
        switch (i) {
            case 0 :
                cout << "       \t |====== STUDENT DATABASE MANAGEMENT SYSTEM ======| \n";
                break;
            case 3 :
                cout << "       \t |                 1. Log   in                    | \n";
                break;
            case 4 :
                cout << "       \t |                 2. Exit  Program               | \n";
                break;
            case 8 :
                cout << "       \t                Select Your Choice :=>  ";
                break;
            default:
                cout << "       \t |                                                | \n";
                break;
        }
    }

    int c = input_Lim(1, 2);

    string passWord;

    if (c == 1) {
        renterIdFlag:
        cout << "Welcome! Please enter your User ID: " << endl;
        int ID = input_Lim(1,1000);

        cout << endl;
        People *p = PeopleDao::selectOnePeople(ID);

        if (p == nullptr) {
            cerr << "People Not Found!" << endl;
            goto renterIdFlag;
        }

        cout << "Hi, " << p->getName() << " , Please enter your password: " << endl;
        // cin >> passWord;

        delete p;

        bool loginFlag = false;

        while(!loginFlag){
            getline(cin >> ws, passWord);
            loginFlag = PeopleServices::login(ID, passWord);
        }

        return ID;

    } else {
        return 0;
    }

}

int teacherMenu(int ID) {
    string new_name;

    string tutor_name;

    string subject_name;

    TeacherServices TS;

    string student_name;

    VariadicTable<int, string> vt({"Options", "Options"});

    vector<string> menu_names = {"Show all students",
                                 "Show all tutors",
                                 "Show all subjects",
                                 "Show all subjects enrolled by ID",
                                 "Add new student",
                                 "Change user's name",
                                 "Add new tutor",
                                 "Add new subject",
                                 "Logout"};

    for (int i = 0; i < menu_names.size(); ++i) {
        vt.addRow(i+1,menu_names[i]);
    }


    vt.print(cout);


    //accepts the command

    //assumed just only numbers

    cout << "Please enter the command of function" << endl;

    int command_1 = input_Lim(1, 9);

    switch (command_1) {
        case 1 : {// show all students
            TS.showStudents();
            break;
        }
        case 2 :// show all tutors
            TS.showTutors();
            break;

        case 3 :// Show all subjects
            TS.showSubjects();
            break;

        case 4 ://Show all subjects enrolled by ID
        {
            PeopleServices::ListAllUsers();
            cout << "Please enter a ID for the account. " << endl;

            int id = input_Lim(1, 1000);

            TS.showSubjectsEnrolledById(id);
            break;
        }
        case 5 ://Change user's name.
        {
            PeopleServices::ListAllUsers();

            cout << "Please enter a ID for the account. " << endl;

            int id = input_Lim(1, 1000);

            cout << "Please enter a new name for your account. " << endl;

            getline(cin >> ws, new_name);

            TS.changeUserName(id, new_name);

            break;
        }
        case 6 ://Add new student.
        {

            cout << "Please enter the student name : " << endl;

            getline(cin >> ws, student_name);

            if (TS.addNewStudent(new Student(0, student_name))) {
                cout << "You have added a student user : " << student_name << " successfully! " << endl;
            } else {
                cout << "You failed to add a student user : " << student_name << "! " << endl;
            }

            break;
        }
        case 7 ://Add new tutor
        {
            cout << "Please enter the tutor name : " << endl;

            getline(cin >> ws, tutor_name);

            if (TS.addNewTutor(new Tutor(0, tutor_name))) {

                cout << "You have added a tutor user : " << tutor_name << " successfully! " << endl;

            } else {

                cout << "You failed to add a tutor user : " << tutor_name << "! " << endl;

            }

            break;
        }
        case 8 ://Add new subject.
        {

            cout << "Please enter the subject name : " << endl;

            getline(cin >> ws, subject_name);

            if (TS.addNewSubject(new Subject(0, subject_name))) {

                cout << "You have added a subject : " << subject_name << " successfully! " << endl;

            } else {

                cout << "You failed to add a subject : " << subject_name << "! " << endl;

            }

            break;
        }
        case 9 ://logout.
        {
            TeacherServices::logout(ID);
            return -1;
        }
        default:
            break;
    }

    std::cout << "press any key to continue ...";
    cin.ignore().get();
    system("clear");

    return 0;

}

int tutorMenu(int ID) {
    string new_name;

    TutorServices TUS;

    string student_name;

    VariadicTable<int, string> vt({"Options", "Options"});

        vt.addRow(1,"Show all students");
        vt.addRow(2,"Show all subjects");
        vt.addRow(3,"Show all subjects enrolled by ID");
        vt.addRow(4,"Change user's name");
        vt.addRow(5,"Add new student");
        vt.addRow(6,"Logout");

    vt.print(cout);

    cout << "Please enter the command of function" << endl;

    int command_2 = input_Lim(1, 6);

    switch (command_2) {
        case 1 :// show all students

            TUS.showStudents();
            break;

        case 2 :// Show all subjects

            TUS.showSubjects();
            break;

        case 3 ://Show all subjects enrolled by ID
        {
            PeopleServices::ListAllUsers();

            cout << "Please enter a ID for the account. " << endl;

            int id = input_Lim(1, 1000);

            TUS.showSubjectsEnrolledById(id);
            break;
        }
        case 4 ://Change user's name.
        {
            PeopleServices::ListAllUsers();

            cout << "Please enter a ID for the account. " << endl;

            int id = input_Lim(1, 1000);

            cout << "Please enter a new name for your account. " << endl;

            getline(cin >> ws, new_name);

            TUS.changeUserName(id, new_name);

            break;
        }
        case 5 ://Add new student.

        {
            cout << "Please enter the student name : " << endl;

            getline(cin >> ws, student_name);
            if (TUS.addNewStudent(new Student(0, student_name))) {
                cout << "You have added a student user : " << student_name << " successfully! " << endl;
            } else {
                cout << "You failed to add a student user : " << student_name << "! " << endl;
            }

            break;
        }
        case 6: {
            TutorServices::logout(ID);
            return -1;
        }

        default:
            break;
    }

    std::cout << "press any key to continue ...";
    cin.ignore().get();
    system("clear");


    return 0;
}

int studentMenu(int ID) {

    StudentServices SS;
    VariadicTable<int, string> vt({"Options", "Options"});

    vector<string> menu_names = {"Show all subjects",
                                 "Show all subjects currently enrolled",
                                 "Logout"};

    for (int i = 0; i < menu_names.size(); ++i) {
        vt.addRow(i+1,menu_names[i]);
    }

    vt.print(cout);

    cout << "Please enter the command of function" << endl;

    int command_1 = input_Lim(1, 9);

    switch (command_1) {
        case 1:
            SS.showSubjects();
            break;

        case 2:

            SS.showSubjectsEnrolledById(ID);
            break;

        case 3:
            StudentServices::logout(ID);
            return -1;

        default:
            break;
    }

    std::cout << "press any key to continue ...";
    cin.ignore().get();
    system("clear");

    return 0;

}






