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

private:
    int messageID;
    int studentID;
    int requestSubjectID;
    int tutorID = 0;
    std::string tutorComment;

};


#endif //OOP_PROJECT_MESSAGE_H
