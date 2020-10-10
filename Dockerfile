FROM ubuntu:18.04 AS builder
RUN apt-get update && \
    apt-get install -y git sudo && \
    cd /root/ && \
    git clone https://github.com/UAws/OOP-Project.git && \
    cd /root/OOP-Project/script/ && \
    ./build_onCS50.sh

FROM ubuntu:18.04
WORKDIR /root/
COPY --from=builder /root/OOP-Project/build_test/MainSelf .
COPY --from=builder /root/OOP-Project/utils/db.sql .
RUN apt-get update && apt-get install -y mariadb-server && service mysql start && apt-get clean && \
    mysql -e "create database oop;USE mysql;UPDATE user SET plugin='mysql_native_password' WHERE User='root';FLUSH PRIVILEGES;" && \
    mysql oop < ./db.sql && rm -rf ./db.sql

CMD service mysql start && /root/MainSelf