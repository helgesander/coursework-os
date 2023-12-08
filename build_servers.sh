#!/bin/bash 

if ! command -v make &> /dev/null
then
    sudo apt install make
fi

make -B

./second_log & 
./second_server &
./first_log &
./first_server &