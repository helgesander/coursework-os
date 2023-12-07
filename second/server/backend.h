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
#include <vector>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <csignal>
#include <cstdlib>

#define BUFSIZE 50
#define PIPE_NAME "/tmp/log_pipe"
#define MAX_BUF 100

int fd, serverSocket; // need to clear after Ctrl + C
char* log_string;

const char *const pipe_name = "/tmp/log_pipe";
const char* server_name = "[second_server]";

enum DATA_FLAGS {
    GET_SCREENSIZE,
    GET_PROCESS_TIME
};

std::pair<int, int> getScreensize();
int getProcessTime();
void clientHandler(int clientSocket);
void signalHandler(int);
void log(const char[]);

#endif //JULIA_COURSEWORK_WORKING_TIME_AND_SCREENSIZE_SRV_H
