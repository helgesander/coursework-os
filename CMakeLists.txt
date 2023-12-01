cmake_minimum_required(VERSION 3.10)

project(second_server)

# Добавляем подкаталоги для обоих серверов
add_subdirectory(second/log_srv)
add_subdirectory(second/server)
