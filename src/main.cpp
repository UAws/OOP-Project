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
#include <cctype>  // isdigit()
#include <service/include/SERVICE_PUBLIC.h>
#include <vo/include/VO_PUBLIC.h>
#include <dao/include/PeopleDao.h>
#include <dao/include/SubjectDao.h>

using namespace std;

int input_Limit(int start, int end);

int init();

int teacherMenu(int ID);

int tutorMenu(int ID);

int studentMenu(int ID);

int main(int argc, char **argv) {

    while (true) {


        int ID = init();

    // ----------------------------------------------------------------------------------------------------------------------------------
    // distinguish the user level and goto the corresponding menu

        // goto teacherMenu
        if (PeopleServices::checkUserLevelById(ID) == 3) {

            int goBackFlag = teacherMenu(ID);

            while(goBackFlag == 0){
                goBackFlag = teacherMenu(ID);
            }

        // goto tutorMenu
        } else if (PeopleServices::checkUserLevelById(ID) == 2) {

            int goBackFlag = tutorMenu(ID);

            while(goBackFlag == 0){
                goBackFlag = tutorMenu(ID);
            }


        // goto studentMenu
        } else if (PeopleServices::checkUserLevelById(ID) == 1) {

            int goBackFlag = studentMenu(ID);

            while(goBackFlag == 0){
                goBackFlag = studentMenu(ID);
            }

        }

        if (ID == -1) {
            break;
        }

    }

    return 0;
}


// input limit, only accept whole number that lie between our defined start & end
int input_Limit(int start, int end) {

    int result = 0;
    int errorCount = 0;

// error checking loop
while(true) {
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

enum class TeacherMenuSelection {
    ShowAllStudents = 1,
    ShowAllTutors = 2,
    ShowAllSubjects = 3,
    ShowAllSubjuctsByID = 4,
    ChangeUserName = 5,
    AddNewStudent = 6,
    AddNewTutor = 7,
    AddNewSubject = 8,
    UnlockUserByID = 9,
    ReviewJoinRequest = 10,
    Logout = 11,
};

enum class TutorMenuSelection {
    ShowAllStudents = 1,
    ShowAllSubjects = 2,
    ShowAllSubjuctsByID = 3,
    ChangeUserName = 4,
    AddNewStudent = 5,
    ReviewJoinRequest = 6,
    Logout = 7,

};


enum class StudentMenuSelection {
    ShowAllSubjects = 1,
    ShowEnroledSubject = 2,
    NewSubjectRequest = 3,
    Logout = 4,

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


  
// achieve basic functions: login, see users' info, exit
    const int menuSelectionCount = 3;
    InitMenuSelection choice = (InitMenuSelection) input_Limit(1, menuSelectionCount); // 1 to bring into range of 1-3

    string passWord = "";

    if (choice == InitMenuSelection::Login) {
        cout << "Welcome! Please enter your User ID: " << endl;

        const int minIDNumber = 1;
        const int maxIDNumber = 1000;

        int ID = input_Limit(minIDNumber, maxIDNumber);

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

    } else if (choice == InitMenuSelection::ShowInfo) {

        PeopleServices::ListAllUsers();

        std::cout << "press enter key to continue ...";
        cin.ignore().get();
        system("clear");

        return -2;

    } else if (choice == InitMenuSelection::Exit) {
        return -1;
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
                                 "Review joining request",
                                 "Logout"};

    for (size_t i = 0; i < menu_names.size(); ++i) {
        vt.addRow(i+1,menu_names[i]);
    }



    vt.print(cout);


    //accepts the command

    //assumed just only numbers

    cout << "Please enter the command of function" << endl;
    const int menuSelectionCount = 11;
    TeacherMenuSelection choice = (TeacherMenuSelection) input_Limit(1, menuSelectionCount);


    switch (choice) {
        case TeacherMenuSelection::ShowAllStudents: {// show all students
            TS.showStudents();
            break;
        }
        case TeacherMenuSelection::ShowAllTutors :// show all tutors
            TS.showTutors();
            break;

        case TeacherMenuSelection::ShowAllSubjects :// Show all subjects
            TS.showSubjects();
            break;

        case TeacherMenuSelection::ShowAllSubjuctsByID ://Show all subjects enrolled by ID
        {
            PeopleServices::ListAllUsers();
            cout << "Please enter a ID for the account. " << endl;

            int id = input_Limit(1, 1000);

            TS.showSubjectsEnrolledById(id);
            break;
        }
        case TeacherMenuSelection::ChangeUserName ://Change user's name.
        {
            PeopleServices::ListAllUsers();

            cout << "Please enter a ID for the account. " << endl;

            int id = input_Limit(1, 1000);

            cout << "Please enter a new name for your account. " << endl;

            getline(cin >> ws, new_name);

            TS.changeUserName(id, new_name);

            break;
        }
        case TeacherMenuSelection::AddNewStudent ://Add new student.
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
        case TeacherMenuSelection::AddNewTutor ://Add new tutor
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
        case TeacherMenuSelection::AddNewSubject ://Add new subject.
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
        case TeacherMenuSelection::UnlockUserByID : {
            cout << "Please enter a ID for the account. " << endl;

            int id = input_Limit(1, 1000);

            if(TeacherServices::unlockUser(id)){
                cout << "user with ID : " << id  << "unlocked" << endl;
            }else{
                cout << "user with ID : " << id  << "unlock failed , please contact administrator" << endl;
            }
            break;

        }

        case TeacherMenuSelection::ReviewJoinRequest: {

            PeopleServices::showCommunication();
            cout << "Please enter the message ID. " << endl;

            const int maxMessageID = Storage::messageArray.size();

            if (maxMessageID >= 0){

                int messageID = input_Limit(1, maxMessageID);

                cout << "Do you want to approve this request , enter 1 to approve , anything else to deny " << endl;


                string approve ;

                getline(cin >> ws, approve);

                TS.communicate(messageID, approve);
                
            }


            break;

        }
        case TeacherMenuSelection::Logout ://logout.
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

    const int menuSelectionCount = 7;
    TutorMenuSelection choice = (TutorMenuSelection) input_Limit(1, menuSelectionCount);

    switch (choice) {
        case TutorMenuSelection::ShowAllStudents :// show all students

            TUS.showStudents();
            break;

        case TutorMenuSelection::ShowAllSubjects :// Show all subjects

            TUS.showSubjects();
            break;

        case TutorMenuSelection::ShowAllSubjuctsByID ://Show all subjects enrolled by ID
        {
            PeopleServices::ListAllUsers();

            cout << "Please enter a ID for the account. " << endl;

            int id = input_Limit(1, 1000);

            TUS.showSubjectsEnrolledById(id);
            break;
        }
        case TutorMenuSelection::ChangeUserName ://Change user's name.
        {
            PeopleServices::ListAllUsers();

            cout << "Please enter a ID for the account. " << endl;

            int id = input_Limit(1, 1000);

            cout << "Please enter a new name for your account. " << endl;

            getline(cin >> ws, new_name);

            TUS.changeUserName(id, new_name);

            break;
        }
        case TutorMenuSelection::AddNewStudent ://Add new student.

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
        case TutorMenuSelection::ReviewJoinRequest: {

            PeopleServices::showCommunication();
            cout << "Please enter the message ID. " << endl;

            const int maxMessageID = Storage::messageArray.size();

            if (maxMessageID >= 0){

                int messageID = input_Limit(1, maxMessageID);

                cout << "Please enter the comments : " << endl;


                string comments ;

                getline(cin >> ws, comments);

                TUS.communicate(messageID, comments);

            }

            break;
        }
        case TutorMenuSelection::Logout: {
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

int studentMenu(int ID) {

    StudentServices SS;
    VariadicTable<int, string> vt({"Options", "Options"});

    vector<string> menu_names = {"Show all subjects",
                                 "Show all subjects currently enrolled",
                                 "Request to join a new subject",
                                 "Logout"};

    for (size_t i = 0; i < menu_names.size(); ++i) {
        vt.addRow(i+1,menu_names[i]);
    }

    vt.print(cout);

    cout << "Please enter the command of function" << endl;

    const int menuSelectionCount = 4;
    StudentMenuSelection choice = (StudentMenuSelection) input_Limit(1, menuSelectionCount);

    switch (choice) {
        case StudentMenuSelection::ShowAllSubjects:
            SS.showSubjects();
            break;

        case StudentMenuSelection::ShowEnroledSubject:

            SS.showSubjectsEnrolledById(ID);
            break;

        case StudentMenuSelection::NewSubjectRequest:
        {
            SS.showSubjects();

            cout << "Please enter the subject ID request to join. " << endl;

            const int maxSubjectID = SubjectDao::listAllSubjects().size();

            if (maxSubjectID != 0){
                int subjectID = input_Limit(1, maxSubjectID);

                SS.communicate(subjectID, "");
            }

            break;
        }

        case StudentMenuSelection::Logout:

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






