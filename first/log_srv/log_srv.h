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

#define PIPE_NAME "/tmp/first_log_pipe"
#define BUFSIZE 128

const std::string log_name = "first_server.log";
const char* server_name = "[first_log_srv]";

#endif
