// Author : Akide Liu 
// Date : 20/10/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "vo/include/Message.h"

Message::Message(int messageId, int studentId, int requestSubjectId) : messageID(messageId), studentID(studentId),
                                                                       requestSubjectID(requestSubjectId) {}

int Message::getMessageId() const {
    return messageID;
}

void Message::setMessageId(int messageId) {
    messageID = messageId;
}

int Message::getStudentId() const {
    return studentID;
}

void Message::setStudentId(int studentId) {
    studentID = studentId;
}

int Message::getRequestSubjectId() const {
    return requestSubjectID;
}

void Message::setRequestSubjectId(int requestSubjectId) {
    requestSubjectID = requestSubjectId;
}

int Message::getTutorId() const {
    return tutorID;
}

void Message::setTutorId(int tutorId) {
    tutorID = tutorId;
}

const std::string &Message::getTutorComment() const {
    return tutorComment;
}

void Message::setTutorComment(const std::string &tutorComment) {
    Message::tutorComment = tutorComment;
}

std::ostream &operator<<(std::ostream &os, const Message &message) {
    os << "messageID: " << message.messageID << " studentID: " << message.studentID << " requestSubjectID: "
       << message.requestSubjectID << " tutorID: " << message.tutorID << " tutorComment: " << message.tutorComment;
    return os;
}

const string &Message::getStudentName() const {
    return studentName;
}

void Message::setStudentName(const string &studentName) {
    Message::studentName = studentName;
}

const string &Message::getTutorName() const {
    return tutorName;
}

void Message::setTutorName(const string &tutorName) {
    Message::tutorName = tutorName;
}

const string &Message::getApprove() const {
    return approve;
}

void Message::setApprove(const string &approve) {
    Message::approve = approve;
}

const string &Message::getSubjectName() const {
    return subjectName;
}

void Message::setSubjectName(const string &subjectName) {
    Message::subjectName = subjectName;
}
