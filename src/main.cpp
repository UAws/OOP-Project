// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 24/9/20
// License and copyright notice: GNU General Public License v3.0 

// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//
#include <iostream>
#include <string>
#include <service/include/SERVICE_PUBLIC.h>
#include <vo/include/VO_PUBLIC.h>
#include <dao/include/PeopleDao.h>
#include <sstream>

using namespace std;

int input_Lim(int start, int end);

int init();

int teacherMenu(int ID);

int tutorMenu(int ID);

int main(int argc, char **argv) {

    initFlag:

    int ID = init();

// ----------------------------------------------------------------------------------------------------------------------------------
    if (PeopleServices::checkUserLevelById(ID) == 3) {

        if (teacherMenu(ID) == -1) {
            goto initFlag;
        }

    } else if (PeopleServices::checkUserLevelById(ID) == 2) {

        if (tutorMenu(ID) == -1) {
            goto initFlag;
        }

    } else if (PeopleServices::checkUserLevelById(ID) == 1) {


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
        cout << "Welcome! Please enter your student ID: ";
        int ID = input_Lim(1,1000);

        cout << endl;
        People *p = PeopleDao::selectOnePeople(ID);

        if (p == nullptr) {
            cerr << "People Not Found!" << endl;
            goto renterIdFlag;
        }

        cout << "Hi, " << p->getName() << ", Please enter your password: ";
        // cin >> passWord;

        getline(cin >> ws, passWord);
        PeopleServices::login(ID, passWord);
    } else {
        return 0;
    }

    return -1;
}

int teacherMenu(int ID) {
    string new_name;

    string tutor_name;

    string subject_name;

    TeacherServices TS;

    string student_name;


    cout << "1 Show all students " << endl;
    cout << "2 Show all tutors " << endl;
    cout << "3 Show all subjects " << endl;
    cout << "4 Show all subjects enrolled by ID. " << endl;
    cout << "5 Change user's name. " << endl;
    cout << "6 Add new student. " << endl;
    cout << "7 Add new tutor. " << endl;
    cout << "8 Add new subject. " << endl;
    cout << "9 Logout " << endl;

    //accepts the command

    //assumed just only numbers

    cout << "Please enter the commond of function" << endl;

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
            TS.showSubjectsEnrolledById(ID);
            break;
        case 5 ://Change user's name.
            cout << "Please enter a new name for your account. " << endl;

            getline(cin >> ws, new_name);
            TS.changeUserName(ID, new_name);

            break;
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

    return 0;

}

int tutorMenu(int ID) {
    string new_name;

    TutorServices TUS;

    string student_name;

    cout << "1 Show all students " << endl;
    cout << "2 Show all subjects " << endl;
    cout << "3 Show all subjects enrolled by ID. " << endl;
    cout << "4 Change user's name. " << endl;
    cout << "5 Add new student. " << endl;
    cout << "6 Logout " << endl;
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
            TUS.showSubjectsEnrolledById(ID);
            break;
        case 4 ://Change user's name.
        {
            cout << "Please enter a new name for your account. " << endl;
            getline(cin >> ws, new_name);
            TUS.changeUserName(ID, new_name);
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
    }

    return 0;
}








