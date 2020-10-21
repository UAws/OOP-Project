# OOP-Project
Student management system



## Try it out by [docker](https://hub.docker.com/r/akide/oop-project):

```
docker run --rm -it akide/oop-project
```



## Build status：

| **master**      | [![Build Status](https://travis-ci.com/UAws/OOP-Project.svg?token=zP1c5kEjbj3paukTcp7U&branch=master)](https://travis-ci.com/UAws/OOP-Project) |
| --------------- | ------------------------------------------------------------ |
| **development** | [![Build Status](https://travis-ci.com/UAws/OOP-Project.svg?token=zP1c5kEjbj3paukTcp7U&branch=development)](https://travis-ci.com/UAws/OOP-Project) |

## Code coverage: [![codecov](https://codecov.io/gh/UAws/OOP-Project/branch/master/graph/badge.svg?token=ON3OHRSFKF)](https://codecov.io/gh/UAws/OOP-Project)

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

### Dependence credits :

- [Google Test](https://github.com/google/googletest)
  - unit test framework
- [prettyprint.hpp](https://github.com/louisdx/cxx-prettyprint)
  - c++ STL cout print 
- [VariadicTable.h](https://github.com/friedmud/variadic_table)
  - beautiful console table print
- [Sqlpp11](https://github.com/rbock/sqlpp11)
  - A type safe SQL template library for C++
- [vcpkg](https://github.com/microsoft/vcpkg) (build sqlpp11-mysql-connector)
  - C++ Library Manager for Windows, Linux, and MacOS
- [Conan](https://github.com/conan-io/conan) (build other dependencies)
  - Conan - The open-source C/C++ package manager



### [Additional Info](https://www.notion.so/OOP-Major-Practical-Design-Student-management-system-C-c84a6cce47864e0a802a3164224915c6#3ae5643700534310b530b856b16c22f1)

