#ifndef JULIA_COURSEWORK_LOG_SRV_H
#define JULIA_COURSEWORK_LOG_SRV_H

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <ctime>

#define BUFSIZE 128

#ifdef SECOND_SERVER

#define PIPE_NAME "/tmp/second_log_pipe"
const std::string log_name = "second_server.log";
const char* server_name = "[second_log_srv]";

#else

#define PIPE_NAME "/tmp/first_log_pipe"
const std::string log_name = "first_server.log";
const char* server_name = "[first_log_srv]";

#endif

enum DATA_FLAGS {
    GET_SCREENSIZE,
    GET_PROCESS_TIME
};

std::string logTime();

#endif
