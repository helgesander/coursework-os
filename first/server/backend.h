#ifndef JULIA_COURSEWORK_FIRST_BACKEND_H
#define JULIA_COURSEWORK_FIRST_BACKEND_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <vector>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>

enum DATA_FLAGS {
    GET_SCREENSIZE,
    GET_PROCESS_TIME
};

int getSwapSize();

#endif
