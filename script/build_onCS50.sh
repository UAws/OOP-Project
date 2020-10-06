#bin/bash

#check running directory
if [ ! -f ../LICENSE ]; then

  echo "YOUR MUSH execute this script at script directory"
  echo "cd script/ ; ./build_dependencies.sh "
  exit

fi

#check system

if command -v apt-get >/dev/null 2>&1; then
      echo ""
else
      echo "this project MUST build on ubuntu or debian linux "
      exit
fi

#define project root directory
cd ..
CURRENT_DIR=`pwd`


#install system build dependency


sudo apt update

sudo apt-get -y install build-essential curl unzip tar pkg-config cmake python-pip gdb dialog apt-utils mariadb-server

sudo service mysql start


sudo pip install conan

#start build test
cd $CURRENT_DIR

sudo mysql -e "create database oop;USE mysql;UPDATE user SET plugin='mysql_native_password' WHERE User='root';FLUSH PRIVILEGES;"
sudo mysql oop < utils/db.sql
sed -i 's/172.16.0.78/127.0.0.1/g' utils/database_connection.cpp
sed -i 's/LJi8kLPc2KaGjEJF//g' utils/database_connection.cpp
sed -i 's/user = "oop"/user = "root"/g' utils/database_connection.cpp

mkdir build_test/
cd build_test/
cmake -DCMAKE_BUILD_TYPE=debug .. && make

if [ -f ./GTestSelf  ]; then
    ./GTestSelf

    if [ $? != "0" ]; then
    exit 1
    fi

    cd $CURRENT_DIR
#    if [ -d build_test ]; then
#        rm -rf build_test/
#    fi

    echo "dependencies build successfully"

else
    echo "build dependencies failed "
    exit 1
fi


cd $CURRENT_DIR || exit




