cmake_minimum_required(VERSION 3.10)

# Задаем имя проекта
project(server)

# Добавляем исполняемый файл для сервера second_server
add_executable(second_server backend.cpp backend.h)

find_package(X11 REQUIRED)

include_directories(${X11_INCLUDE_DIR})

target_link_libraries(second_server ${X11_LIBRARIES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")