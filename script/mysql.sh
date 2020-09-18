#! /bin/bash

if [ ! -x ../lib/googletest/googletest ]; then
cd ../lib/ || exit
git config credential.helper store
git clone https://github.com/google/googletest.git
cd - || exit
fi


if command -v mysql >/dev/null 2>&1; then
  echo 'exists mysql'
else
  echo 'no exists mysql'
  sudo apt update -y
  sudo apt-get install default-mysql-client -y
fi

HOST="172.16.0.78"
USER="oop"
PASSWORDS="LJi8kLPc2KaGjEJF"

mysql -h$HOST -u $USER -p$PASSWORDS -e"show databases;"


