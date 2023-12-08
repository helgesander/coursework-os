#include "backend.h"

int main(int argc, char* argv[]) {
    time_t start_time = time(NULL);
    log_string = new char[MAX_BUF + 1];
    strcpy(log_string, server_name);
    signal(SIGINT, signalHandler);
    if (mkfifo(PIPE_NAME, 0777)) {
        unlink(pipe_name);
        mkfifo(PIPE_NAME, 0777);
    }
    fd = open(PIPE_NAME, O_WRONLY);
    if (fd == -1) {
        std::string rm = "rm ";
        rm.append(pipe_name);
        system(rm.c_str());
        delete(log_string);
        return 1;
    }
    log("Starting server\n");
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientStructLen;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        log("Error to create socket\n");
        std::string rm = "rm ";
        rm.append(pipe_name);
        system(rm.c_str());
        delete(log_string);
        write(fd, "EXIT", 5);
        close(fd);
        return 1;
    }
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(PORT);
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        log("Error with binding socket\n");
        std::string rm = "rm ";
        rm.append(pipe_name);
        system(rm.c_str());
        delete(log_string);
        write(fd, "EXIT", 5);
        close(fd);
        return 1;
    }
    listen(serverSocket, SOMAXCONN);
    while (true)
    {
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientStructLen);
        if (clientSocket < 0) {
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
            std::thread t(clientHandler, clientSocket, start_time, ipstr);
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

int getProcessTime(time_t time_from_start) {
    time_t current_time = time(NULL);
    return static_cast<int>(current_time - time_from_start); 
}

void clientHandler(int clientSocket, time_t start_time, const char* ipstr) {
    char buffer[10];
    std::size_t sz = 10;
    bool exit = false;
    while (!exit) {
        std::string tmp = "Client from ";
        tmp.append(ipstr); 
        int rc = recv(clientSocket, buffer, 10, 0);
        int flag = std::stoi(buffer, &sz, 10);
        if (rc < 0) {
            tmp.append(ipstr);
            tmp.append(": Error with reading data from client\\n");
            log(tmp.c_str());
        } else {
            std::string response;
            std::pair<int, int> screensize_response;
            int time_response;
            switch (flag) {
                case GET_SCREENSIZE:
                    screensize_response = getScreensize(); 
                    tmp.append(" ask screen size: ");
                    response = std::to_string(screensize_response.first) + " " + std::to_string(screensize_response.second);
                    tmp.append(response);
                    tmp.push_back('\n');
                    log(tmp.c_str());
                    send(clientSocket, response.c_str(), response.length(), 0);
                    break;
                case GET_PROCESS_TIME: 
                    time_response = getProcessTime(start_time);
                    tmp.append(" ask server uptime: ");
                    response = std::to_string(time_response);   
                    tmp.append(response);
                    tmp.push_back('\n');
                    log(tmp.c_str());
                    send(clientSocket, response.c_str(), response.length(), 0);
                    break;
                case CLOSE_CONNECTION:
                    exit = true;
                    break;
                default:
                    tmp.append(": bad choice\n");
                    send(clientSocket, "bad choice", 11, MSG_NOSIGNAL);
                    log(tmp.c_str());
                }
            }
        }
    std::string close_connection = "Client from ";
    close_connection.append(ipstr);
    close_connection.append(" close connection\n");
    log(close_connection.c_str());
    close(clientSocket);
}

void signalHandler(int signal) {
    log("Server is shutdown...\n");
    close(serverSocket);
    std::string rm = "rm ";
    rm.append(pipe_name);
    system(rm.c_str());
    delete(log_string);
    write(fd, "EXIT", 5);
    close(fd);
    exit(signal);
}

void log(const char str[]) {
    strcat(log_string, " ");
    strcat(log_string, str);
    write(fd, log_string, strlen(log_string));
    strcpy(log_string, server_name);
}