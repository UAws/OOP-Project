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

using namespace std;

int input_Lim(int start, int end) {
    const string START = to_string(start);
    const string END = to_string(end);
    string inputNum;
    cout<<"";
    while(1){
        cin >> inputNum;
        if (inputNum.size() == 1 && inputNum >= START && inputNum <= END){
            break;
        }
        else{
            cout<<"input error! Please enter again:";
        }
    }
    int n=stoi(inputNum);
    return n;
}


int main() {

    initFlag:
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
// cout << c << endl;

    int ID;
    string passWord;
    PeopleServices thePeople;

    if (c == 1) {
        cout << "Welcome! Please enter your student ID: ";
        cin >> ID;

        cout << endl;
        People *p = PeopleDao::selectOnePeople(ID);

        cout << "Hi, " << p->getName() << ", Please enter your password: ";
        cin >> passWord;

        thePeople.login(ID, passWord);
    } else {
        return 0;
    }

    resetFlag:
// ----------------------------------------------------------------------------------------------------------------------------------
    if (thePeople.checkUserLevelById(ID) == 3) {

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

                cin >> new_name;

                TS.changeUserName(ID, new_name);

                break;
            case 6 ://Add new student.
            {

                cout << "Please enter the student name : " << endl;

                cin >> student_name;

                Student *new_student = new Student(0, student_name);

                if (TS.addNewStudent(new_student)) {
                    cout << "You have added a student user : " << student_name << " successfully! " << endl;
                } else {
                    cout << "You failed to add a student user : " << student_name << "! " << endl;
                }

                break;
            }
            case 7 ://Add new tutor
            {
                cout << "Please enter the tutor name : " << endl;

                cin >> tutor_name;

                auto *new_tutor = new Tutor(0, tutor_name);

                if (TS.addNewTutor(new_tutor)) {

                    cout << "You have added a tutor user : " << tutor_name << " successfully! " << endl;

                } else {

                    cout << "You failed to add a tutor user : " << tutor_name << "! " << endl;

                }

                delete new_tutor;

                break;
            }
            case 8 ://Add new subject.
            {

                cout << "Please enter the subject name : " << endl;

                cin >> subject_name;

                Subject *new_subject = new Subject(0, subject_name);

                if (TS.addNewSubject(new_subject)) {

                    cout << "You have added a subject : " << subject_name << " successfully! " << endl;

                } else {

                    cout << "You failed to add a subject : " << subject_name << "! " << endl;

                }

                delete new_subject;

                break;
            }
            case 9 ://logout.
            {
                TS.logout(ID);
                goto initFlag;
                break;
            }
            default:
                break;
        }

        goto resetFlag;


    } else if (thePeople.checkUserLevelById(ID) == 2) {

        string new_name;

        TutorServices TUS;

        string student_name;

        cout << "1 Show all students " << endl;
        cout << "2 Show all subjects " << endl;
        cout << "3 Show all subjects enrolled by ID. " << endl;
        cout << "4 Change user's name. " << endl;
        cout << "5 Add new student. " << endl;
        cout << "6 Logout " << endl;
        cout << "Please enter the commond of function" << endl;

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
                cin >> new_name;
                TUS.changeUserName(ID, new_name);
                break;
            }
            case 5 ://Add new student.

            {
                cout << "Please enter the student name : " << endl;

                cin >> student_name;

                Student *new_student = new Student(0, student_name);

                if (TUS.addNewStudent(new_student)) {
                    cout << "You have added a student user : " << student_name << " successfully! " << endl;
                } else {
                    cout << "You failed to add a student user : " << student_name << "! " << endl;
                }

                break;
            }
            case 6: {
                TUS.logout(ID);
                break;
            }
        }


    } else if (thePeople.checkUserLevelById(ID) == 1) {


    }
}










