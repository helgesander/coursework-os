#ifndef JULIA_COURSEWORK_LOG_SRV_H
#define JULIA_COURSEWORK_LOG_SRV_H

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define PIPE_NAME "/tmp/log_pipe"
#define BUFSIZE 128

const std::string log_name = "second_server.log";
const char* server_name = "[log_srv]";

enum DATA_FLAGS {
    GET_SCREENSIZE,
    GET_PROCESS_TIME
};

#endif
