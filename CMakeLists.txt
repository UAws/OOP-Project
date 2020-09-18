cmake_minimum_required(VERSION 3.10)
project(Cpp)

add_definitions(-Wall)
set(CMAKE_CXX_STANDARD 11)

set(googleTestDir lib/googletest)

#Add the google test subdirectory
add_subdirectory(${googleTestDir})
#include googletest/include dir
include_directories(${googleTestDir}/googletest/include)
#include the googlemock/include dir
include_directories(${googleTestDir}/googlemock/include)

set(major_project
        Test/project_test.cpp
        src/People.cpp
        src/Storage.cpp
        src/Student.cpp
        src/Subject.cpp
        src/Teacher.cpp
        src/Tutor.cpp
        )
add_executable(GTest ${major_project})
add_compile_definitions(GTest_ignore)
target_link_libraries(GTest gtest gtest_main)
target_link_libraries(GTest gmock gmock_main)