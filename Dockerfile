FROM ubuntu:18.04
RUN apt-get update && apt-get install -y git sudo
RUN cd ~/ && git clone https://github.com/UAws/OOP-Project.git && cd ~/OOP-Project/script/ && ./build_onCS50.sh
CMD service mysql start && /root/OOP-Project/build_test/MainSelf