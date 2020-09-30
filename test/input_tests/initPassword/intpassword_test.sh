#!/bin/sh

CURRENT_DIR=$(pwd)

cd ../../../

EXEFile=$(find "$(pwd -P)"  -name 'GTestSelfInput' | head -1)

cd $CURRENT_DIR

$EXEFile --gtest_filter=People_Services_input.initPassword01 < input1.txt

if [ $? != "0" ]; then
    exit 1
fi

$EXEFile --gtest_filter=People_Services_input.initPassword02 < input2.txt

if [ $? != "0" ]; then
    exit 1
fi


$EXEFile --gtest_filter=People_Services_input.login01

if [ $? != "0" ]; then
    exit 1
fi

$EXEFile --gtest_filter=People_Services_input.login02 < input1.txt

if [ $? != "0" ]; then
    exit 1
fi

$EXEFile --gtest_filter=People_Services_input.login03 < input2.txt

if [ $? != "0" ]; then
    exit 1
fi
