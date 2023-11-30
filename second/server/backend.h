#ifndef JULIA_COURSEWORK_WORKING_TIME_AND_SCREENSIZE_SRV_H
#define JULIA_COURSEWORK_WORKING_TIME_AND_SCREENSIZE_SRV_H

#include <X11/Xlib.h>
#include <utility>
#include <unistd.h>
#include <thread>
#include <iostream>
#include <ctime>
#include <utility>
#include <sys/socket.h>
#include <vector>
#include <cstring>
#include <netinet/in.h>

enum DATA_FLAGS {
    GET_SCREENSIZE,
    GET_PROCESS_TIME
};

#endif //JULIA_COURSEWORK_WORKING_TIME_AND_SCREENSIZE_SRV_H
