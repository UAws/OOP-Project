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

sudo apt-get -y install build-essential curl unzip tar pkg-config cmake python-pip gdb

sudo pip install conan

#start build test
cd $CURRENT_DIR

mkdir build_test/
cd build_test/
cmake -DCMAKE_BUILD_TYPE=debug .. && make -j 12

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




