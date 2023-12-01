cmake_minimum_required(VERSION 3.10)

# Задаем имя проекта
project(log_srv)

# Добавляем исполняемый файл для сервера log_srv
add_executable(log_server log_srv.cpp log_srv.h)

find_package(X11 REQUIRED)

include_directories(${X11_INCLUDE_DIR})

target_link_libraries(log_server ${X11_LIBRARIES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")