// Author : Akide Liu 
// Date : 20/10/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef OOP_PROJECT_MESSAGE_H
#define OOP_PROJECT_MESSAGE_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Message {


public:
    int getMessageId() const;

    void setMessageId(int messageId);

    int getStudentId() const;

    void setStudentId(int studentId);

    int getRequestSubjectId() const;

    void setRequestSubjectId(int requestSubjectId);

    int getTutorId() const;

    void setTutorId(int tutorId);

    const std::string &getTutorComment() const;

    void setTutorComment(const std::string &tutorComment);

    Message(int messageId, int studentId, int requestSubjectId);

    friend std::ostream &operator<<(std::ostream &os, const Message &message);

    const string &getStudentName() const;

    void setStudentName(const string &studentName);

    const string &getTutorName() const;

    void setTutorName(const string &tutorName);

    const string &getApprove() const;

    void setApprove(const string &approve);

    const string &getSubjectName() const;

    void setSubjectName(const string &subjectName);


private:
    int messageID;
    int studentID;
    int requestSubjectID;
    int tutorID = 0;
    string subjectName;
    string studentName;
    string tutorName;
    string approve;
    std::string tutorComment;

};


#endif //OOP_PROJECT_MESSAGE_H
