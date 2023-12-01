#include "backend.h"

int main(int argc, char* argv[]) {
    log_string = new char[MAX_BUF + 1];
    strcpy(log_string, server_name);
    signal(SIGINT, signalHandler);
    std::cout << "Starting server" << std::endl;
    log("Starting server\n");
    if (mkfifo(PIPE_NAME, 0777)) {
        unlink(pipe_name);
        mkfifo(PIPE_NAME, 0777);
    }
    fd = open(PIPE_NAME, O_WRONLY);
    if (fd == -1) {
        std::cerr << "Cannot open pipe" << std::endl;
        log("Cannot open pipe\n");
        return -1;
    }
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientStructLen;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Error to create socket" << std::endl;
        log("Error to create socket\n");
        return -1;
    }
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(12345);
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error with binding to socker" << std::endl;
        log("Error with binding socket\n");
        return -1;
    }
    listen(serverSocket, SOMAXCONN);
    while (true)
    {
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientStructLen);
        if (clientSocket < 0) {
            std::cout << "Error with connection to server" << std::endl;
            log("Error with connection to server\n");
            continue;
        } else {
            char ipstr[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(clientAddr.sin_addr), ipstr, INET_ADDRSTRLEN);
            char tmp_str[] = "Connection established from ";
            strcat(tmp_str, ipstr);
            strcat(tmp_str, "\n");
            log(tmp_str);
            strcpy(log_string, server_name);
            std::thread t(clientHandler, clientSocket);
            t.detach();
        }
    }
    return 0;
}

std::pair<int, int> getScreensize()
{
    int width, height;
    std::pair<int, int> res;
    Display *display = XOpenDisplay(nullptr);
    if (display) {
        int screen = DefaultScreen(display);
        width = DisplayWidth(display, screen);
        height = DisplayHeight(display, screen);
        res = std::make_pair(width, height);
    }
    else res = std::make_pair(NULL, NULL);
    XCloseDisplay(display);
    return res;
}

int getProcessTime() {
    clock_t time = clock();
    std::cout << time << std::endl;
    return int(double(time) / CLOCKS_PER_SEC);
}

void clientHandler(int clientSocket) {
    char buffer[10];
    std::size_t sz = 10;
    int rc = recv(clientSocket, buffer, 10, 0);
    int flag = std::stoi(buffer, &sz, 10);
    std::cout << flag << std::endl;
    if (rc < 0) {
        std::cerr << "Error with reading data from client" << std::endl;
        log("Error with reading data from client\\n");
    } else {
        if (flag != GET_PROCESS_TIME && flag != GET_SCREENSIZE) {
            std::cerr << "Bad choice" << std::endl;
            log("Bad choice\n");
        }
        else {
            std::string response;
            if (flag == GET_SCREENSIZE) {
                auto tmp_response = getScreensize();
                response = std::to_string(tmp_response.first) + " " + std::to_string(tmp_response.second);
                send(clientSocket, response.c_str(), response.length(), 0);
            } else {
                int tmp_response = getProcessTime();
                response = std::to_string(tmp_response);
                send(clientSocket, response.c_str(), response.length(), 0);
            }
        }
    }
    close(clientSocket);
}

void signalHandler(int signal) {
//    strcat(log_string, " Server is shutdown...");
    log("Server is shutdown...");
    close(serverSocket);
    close(fd);
    std::string rm = "rm " + pipe_name;
    system(rm.c_str());
    delete(log_string);
    exit(signal);
}

bool log(char str[]) {
    strcat(log_string, " ");
    strcat(log_string, str);
    write(fd, log_string, strlen(log_string));
    strcpy(log_string, server_name);
}