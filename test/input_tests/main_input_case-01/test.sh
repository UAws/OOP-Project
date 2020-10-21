CURRENT_DIR=$(pwd)

cd ../../../

mysql oop < utils/db.sql

EXEFile=$(find "$(pwd -P)"  -name 'MainSelf' | head -1)

cd $CURRENT_DIR

$EXEFile < input.txt \
  | grep -v '-' \
  | grep -v 'enter' \
  > output.txt

if [ $? != "0" ]; then
    exit 1
fi

diff output.txt result.txt

if [ $? != "0" ]; then
    cat output.txt
    exit 1
fi


# use ofstream to print out test 
