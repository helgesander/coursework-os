#ifndef JULIA_COURSEWORK_WORKING_TIME_AND_SCREENSIZE_SRV_H
#define JULIA_COURSEWORK_WORKING_TIME_AND_SCREENSIZE_SRV_H

#define _CRT_SECURE_NO_WARNINGS

#include <X11/Xlib.h>
#include <utility>
#include <unistd.h>
#include <thread>
#include <iostream>
#include <ctime>
#include <utility>
#include <sys/socket.h>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <csignal>
#include <cstdlib>

#define BUFSIZE 50
#define PIPE_NAME "/tmp/second_log_pipe"
#define MAX_BUF 100

int fd, serverSocket; // need to clear after Ctrl + C
char* log_string;

const char *const pipe_name = "/tmp/second_log_pipe";
const char* server_name = "[second_server]";
const std::string null(BUFSIZE - 1, '\0');

enum DATA_FLAGS {
    GET_SCREENSIZE,
    GET_PROCESS_TIME
};

std::pair<int, int> getScreensize();
int getProcessTime(time_t);
void clientHandler(int clientSocket, time_t start_time, const char* ipstr);
void signalHandler(int);
void log(const char[]);

#endif //JULIA_COURSEWORK_WORKING_TIME_AND_SCREENSIZE_SRV_H
