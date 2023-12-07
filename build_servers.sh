#!/bin/bash 

if ! command -v make &> /dev/null
then
    sudo apt install make
fi

cd first && make 
cd ../second && make 

cd .. 

# # Запускаем первый сервер 
# ## TODO: run first server 
# ./first_server & 
# ./first_log_server & 

# # Запускаем второй сервер
# ## TODO: run second server
# ./second_server &
# ./second_log_server & 
