#ifndef JULIA_COURSEWORK_FIRST_BACKEND_H
#define JULIA_COURSEWORK_FIRST_BACKEND_H

#include <sys/sysinfo.h>
#include <unistd.h>
#include <thread>
#include <iostream>
#include <sys/socket.h>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <csignal>

#define BUFSIZE 50
#define PIPE_NAME "/tmp/first_log_pipe"
#define MAX_BUF 100

int fd, serverSocket; // need to clear after Ctrl + C
char* log_string;

const char *const pipe_name = "/tmp/first_log_pipe";
const char* server_name = "[first_server]";
const std::string null(BUFSIZE - 1, '\0');

enum DATA_FLAGS {
    CLOSE_CONNECTION,        /* 0 */
    GET_SWAP_SIZE,           /* 1 */
    GET_FREE_SWAP_BYTES      /* 2 */         
};

int getSwapSize();
int getFreeSwapBytes();
void signalHandler(int signal);
void log(const char str[]);
void clientHandler(int clientSocket, const char* ipstr);
void errorHandler();

#endif
