# OOP-Project
Student management system

## System design

![University students management platform](https://cdn.jsdelivr.net/gh/AkideLiu/image@master/uPic/image-20200918evn1cD.png)

### Introduction

We are trying to contribute a basic student info management system.

 

### Fixtures: 

#### Students:

When a student first logs in, it is required to initialize their password and enrol their courses. 

Suppose that the student has entered wrong password for more than 3 times, the student account would be freeze. 

Successfully logged: information of the student would be shown (information that has been stored in Storage), such as user ID, subject ID and its enrolment status. Then the system would ask the student if he/ she needs to make any change, i.e. sets up a new password / enrol any new subject.

 

#### Tutor: 

When a tutor first logs in, he/ she is automatically enrolled in every course.

Suppose that the tutor has entered wrong password for more than 3 times, the tutor account would be freeze. 

Successfully logged: information of the tutor would be shown (information that has been stored in Storage), such as user ID, all student information etc. Then the system would ask the tutor if he/ she needs to make any change, i.e. re-initialize a student’s password, sets up a new password etc. 

 

#### Course coordinator:

 When a teacher first logs in, he/ she is automatically enrolled in every course.

Suppose that the teacher has entered wrong password for more than 3 times, the password would be reset to the default password. (i.e. 123456)

Successfully logged: information of the teacher would be shown (information that has been stored in Storage), such as user ID, all student tutor information etc. Then the system would ask the teacher if he/ she needs to make any change, i.e. re-initialize a student/tutor’s password, sets up a new password etc. 

 

### Cooperation: 

\-    If any of us would like to modify a function/ add a library, it is required to confirmed with all other group members, and record the library used.

\-    GitHub.

\-    We may use a database to replace the Storage class.