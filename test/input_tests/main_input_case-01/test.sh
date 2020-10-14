CURRENT_DIR=$(pwd)

cd ../../../

mysql oop < utils/db.sql

EXEFile=$(find "$(pwd -P)"  -name 'MainSelf' | head -1)

cd $CURRENT_DIR

$EXEFile < input.txt > output.txt

if [ $? != "0" ]; then
    exit 1
fi

diff output.txt result.txt

if [ $? != "0" ]; then
    exit 1
fi
