#!/bin/bash 

if ! command -v make &> /dev/null
then
    sudo apt install make
fi

sudo apt install libx11-dev

distrib=`awk -F "DISTRIB_ID=" '/DISTRIB_ID=/ {print $2; exit}' /etc/lsb-release`
if [ $distrib = "Ubuntu" ]; then
    make -f Makefile-debian-ubuntu -B
else
    make -B
fi

./second_log & 
./second_server &
./first_log &
./first_server &