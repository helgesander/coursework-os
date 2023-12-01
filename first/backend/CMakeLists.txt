# CMakeList.txt: проект CMake для backend; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("backend")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (first_server "backend.cpp" "backend.h")


