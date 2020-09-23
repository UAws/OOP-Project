cmake_minimum_required(VERSION 3.10)

project(OOP-project)
add_definitions(-Wall)
set(CMAKE_CXX_STANDARD 11)

set(major_project
        Test/project_test.cpp
        Test/database_test.cpp
        src/People.cpp
        src/Storage.cpp
        src/Student.cpp
        src/Subject.cpp
        src/Teacher.cpp
        src/Tutor.cpp
        )
add_executable(GTestSelf ${major_project})

#automatic dependency management

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/develop/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif()

#including dependencies headers
include(${CMAKE_BINARY_DIR}/conan.cmake)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils/sqlpp11-connector-mysql/installed/x64-osx/include)


#link dependencies libraries
conan_cmake_run(REQUIRES

        openssl/1.0.2u
        mysql-connector-c/6.1.11
        gtest/1.10.0
        sqlpp11/0.59

        BASIC_SETUP CMAKE_TARGETS
        BUILD missing)

target_link_libraries(GTestSelf
        CONAN_PKG::gtest
        CONAN_PKG::openssl
        CONAN_PKG::mysql-connector-c
        CONAN_PKG::sqlpp11
        )

#use different sqlpp11-mysql-connector library depending platform

#https://stackoverflow.com/questions/9160335/os-specific-instructions-in-cmake-how-to

if(APPLE)
    target_link_libraries(GTestSelf
            ${CMAKE_CURRENT_SOURCE_DIR}/utils/sqlpp11-connector-mysql/installed/x64-osx/lib/libsqlpp-mysql.a
            )
endif(APPLE)

if(UNIX AND NOT APPLE)
    target_link_libraries(GTestSelf
            ${CMAKE_CURRENT_SOURCE_DIR}/utils/sqlpp11-connector-mysql/installed/x64-linux/lib/libsqlpp-mysql.a
            )
endif(UNIX AND NOT APPLE)
