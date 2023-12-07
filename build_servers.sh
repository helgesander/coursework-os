#!/bin/bash 

if ! command -v make &> /dev/null
then
    sudo apt install make
fi

# cd first && make 
cd second && make 

cd ..

./second_log_server & 
./second_server &