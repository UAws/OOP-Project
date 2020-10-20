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
#include <ctype.h>  // isdigit()
#include <sstream>  // stringstream
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
// distinguish the user level and goto the corresponding menu

    // goto teacherMenu
    if (PeopleServices::checkUserLevelById(ID) == 3) {

        int goBackFlag = teacherMenu(ID);

        while(goBackFlag == 0){
            goBackFlag = teacherMenu(ID);
        }
        if (goBackFlag == -1) {
            goto initFlag;
        }

    // goto tutorMenu
    } else if (PeopleServices::checkUserLevelById(ID) == 2) {

        int goBackFlag = tutorMenu(ID);

        while(goBackFlag == 0){
            goBackFlag = tutorMenu(ID);
        }

        if (goBackFlag == -1) {
            goto initFlag;
        }

    // goto studentMenu
    } else if (PeopleServices::checkUserLevelById(ID) == 1) {

        int goBackFlag = studentMenu(ID);

        while(goBackFlag == 0){
            goBackFlag = studentMenu(ID);
        }

        if (goBackFlag == -1) {
            goto initFlag;
        }
    }

    if (ID == -2) {
            goto initFlag;
    }

    return 0;
}


// int input_Lim(int start, int end) {
//     int  result = 0;
//     int errorCount = 0;
//     bool notDone = true;

//     while(notDone) {

//         string line;
//         getline(std::cin, line);
//         istringstream is(line);

//         char dummy = '\0';

//         // if we fail to extract an int
//         // or we find something apart from whitespace after the int
//         // or the value isn't in range
//         if (!(is >> result) || (is >> std::ws && is.get(dummy)) || (result < start) || (result > end)){
//             errorCount++;
//             int chanceLeft = 5 - errorCount;
//             cout << "input error! Please enter again. You have " << chanceLeft << " chance left" << endl;
//         }
//         else{
//             notDone = false ;
//         }
//         if (errorCount >= 5) {
//                 cout << "Too many wrong input" << endl;
//                 exit(1);
//             }

//     }

//     return result;
// }

// input limit, only accept whole number that lie between our defined start & end
int input_Lim(int start, int end) {

    int result = 0;
    int errorCount = 0;

// error checking loop
while(1) {
    std::cin >> result; 
    // input valid
    if(!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n')
        && result >= start && result <= end) {
        break; // break from while loop
    }
    // input invalid
    else {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        errorCount++;
        int chanceLeft = 5 - errorCount;
        cout << "input error! Please enter again. You have " << chanceLeft << " chance left" << endl;
    }
    if (errorCount >= 5) {
        cout << "Too many wrong input" << endl;
        exit(1);
     }

}
return result;
}

// enum classes: for comparing with input and leading user to corresponding function
enum class InitMenuSelection {
    Login = 1,
    ShowInfo = 2,
    Exit = 3,
};

enum class InitResult {
    Good,
    Bad,
    Exit,
};

// initial user interface, displays basic funtionalities
int init() {
    const int menuLineCount = 9;
    for (int i = 0; i < menuLineCount; i++) {
        switch (i) {
            case 0 :
                cout << "|====== STUDENT DATABASE MANAGEMENT SYSTEM ======| \n";
                break;
            case 3 :
                cout << "|                 1. Log   in                    | \n";
                break;
            case 4 :
                cout << "|                 2. Show  Info                  | \n";
                break;
            case 5 :
                cout << "|                 3. Exit  Program               | \n";
                break;
            case 8 :
                cout << "                Select Your Choice :=>  ";
                break;
            default:
                cout << "|                                                | \n";
                break;
        }
    }



    // int c = input_Lim(1, 3);

//     string passWord;

//     if (c == 1) {
//         renterIdFlag:
//         cout << "Welcome! Please enter your User ID: " << endl;
//         int ID = input_Lim(1,1000);

//         cout << endl;
//         People *p = PeopleDao::selectOnePeople(ID);

//         if (p == nullptr) {
//             cerr << "People Not Found!" << endl;
//             goto renterIdFlag;
//         }

//         cout << "Hi, " << p->getName() << " , Please enter your password: " << endl;
//         // cin >> passWord;

//         delete p;

//         bool loginFlag = false;

//         while(!loginFlag){
//             getline(cin >> ws, passWord);
//             loginFlag = PeopleServices::login(ID, passWord);
//         }

//         return ID;

//     } else {
//         return 0;
//     }

// }

// achieve basic functions: login, see users' info, exit
const int menuSelectionCount = 3;
    InitMenuSelection c = (InitMenuSelection)input_Lim(1,menuSelectionCount); // 1 to bring into range of 1-3

    string passWord = "";

    if (c == InitMenuSelection::Login) {
        cout << "Welcome! Please enter your User ID: " << endl;

        const int minIDNumber = 1;
        const int maxIDNumber = 1000;

        int ID = input_Lim(minIDNumber, maxIDNumber);

        cout << endl;
        People *p = PeopleDao::selectOnePeople(ID);


        if (p == nullptr) {
            cerr << "People Not Found!" << endl;
            return -2;
        }

        cout << "Hi, " << p->getName() << " , Please enter your password: " << endl;
        // cin >> passWord;

        // Try to login until success or out of attempts
        bool loginSuccess = false;
        const int maxLoginAttempts = 3;
        int loginAttemptCount = 0;
        while (!loginSuccess) { 
            getline(cin >> ws, passWord);
            loginSuccess = PeopleServices::login(ID, passWord);
            loginAttemptCount++;
            if (loginAttemptCount >= maxLoginAttempts) {
                cout << "Hi," << p->getName() << "your acount is locked , please contact your tutor or teacher for unlock" << endl;

                PeopleServices::lockUser(ID);

                exit(2);
            }
        }

        delete p;

        return ID;

    } else if (c == InitMenuSelection::ShowInfo) {

        PeopleServices::ListAllUsers();

        std::cout << "press enter key to continue ...";
        cin.ignore().get();
        system("clear");

        return -2;

    } else if (c == InitMenuSelection::Exit) {
        return 0;
    }
    return 0;
}

// show teacherMenu and implment teacher's function
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
                                 "Change user's name",
                                 "Add new student",
                                 "Add new tutor",
                                 "Add new subject",
                                 "unlock user by ID",
                                 "Review joining request"
                                 "Logout"};

    for (size_t i = 0; i < menu_names.size(); ++i) {
        vt.addRow(i+1,menu_names[i]);
    }



    vt.print(cout);


    //accepts the command

    //assumed just only numbers

    cout << "Please enter the command of function" << endl;

    const int command_start_index = 1;
    const int command_end_index = 11;

    int command_1 = input_Lim(command_start_index, command_end_index);

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

            const int minIDNumber = 1;
            const int maxIDNumber = 1000;

            int id = input_Lim(minIDNumber, maxIDNumber);

            TS.showSubjectsEnrolledById(id);
            break;
        }
        case 5 ://Change user's name.
        {
            PeopleServices::ListAllUsers();

            cout << "Please enter a ID for the account. " << endl;

            const int minIDNumber = 1;
            const int maxIDNumber = 1000;

            int id = input_Lim(minIDNumber, maxIDNumber);

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
        case 9 : // unlock one's account
            {
            cout << "Please enter a ID for the account. " << endl;

            const int minIDNumber = 1;
            const int maxIDNumber = 1000;

            int id = input_Lim(minIDNumber, maxIDNumber);

            if(TeacherServices::unlockUser(id)){
                cout << "user with ID : " << id  << "unlocked" << endl;
            }else{
                cout << "user with ID : " << id  << "unlock failed , please contact administrator" << endl;
            }
            break;

        }
        case 10 :// Review joining request
        case 11 ://logout.
        {
            TeacherServices::logout(ID);
            return -1;
        }
        default:
            break;
    }

    std::cout << "press enter key to continue ...";
    cin.ignore().get();
    system("clear");

    return 0;

}

// show tutorMenu and implment tutor's function
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
        vt.addRow(6,"Review joining request");
        vt.addRow(7,"Logout");

    vt.print(cout);

    cout << "Please enter the command of function" << endl;

    const int command_start_index = 1;
    const int command_end_index = 7;

    int command_2 = input_Lim(command_start_index, command_end_index);

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

            const int minIDNumber = 1;
            const int maxIDNumber = 1000;

            int id = input_Lim(minIDNumber, maxIDNumber);


            TUS.showSubjectsEnrolledById(id);
            break;
        }
        case 4 ://Change user's name.
        {
            PeopleServices::ListAllUsers();
    

            cout << "Please enter a ID for the account. " << endl;

            const int minIDNumber = 1;
            const int maxIDNumber = 1000;

            int id = input_Lim(minIDNumber, maxIDNumber);

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
        case 6:// review joining request
        case 7: {
            TutorServices::logout(ID);
            return -1;
        }

        default:
            break;
    }

    std::cout << "press enter key to continue ...";
    cin.ignore().get();
    system("clear");


    return 0;
}

// show studentMenu and implment student's function
int studentMenu(int ID) {

    StudentServices SS;
    VariadicTable<int, string> vt({"Options", "Options"});

    vector<string> menu_names = {"Show all subjects",
                                 "Show all subjects currently enrolled",
                                 "Request to join a new subject"
                                 "Logout"};

    for (size_t i = 0; i < menu_names.size(); ++i) {
        vt.addRow(i+1,menu_names[i]);
    }

    vt.print(cout);

    cout << "Please enter the command of function" << endl;

    const int command_start_index = 1;
    const int command_end_index = 4;

    int command_1 = input_Lim(command_start_index, command_end_index);

    switch (command_1) {
        case 1:
            SS.showSubjects();
            break;

        case 2:

            SS.showSubjectsEnrolledById(ID);
            break;

        case 3: // request join a new subject 
            
        case 4:
            StudentServices::logout(ID);
            return -1;

        default:
            break;
    }

    std::cout << "press enter key to continue ...";
    cin.ignore().get();
    system("clear");

    return 0;

}






