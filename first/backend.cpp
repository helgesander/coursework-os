#include "backend.h"

int main() {
    log_string = new char[MAX_BUF + 1];
    strcpy(log_string, server_name);
    signal(SIGINT, signalHandler);
    if (mkfifo(PIPE_NAME, 0777)) {
        unlink(pipe_name);
        mkfifo(PIPE_NAME, 0777);
    }
    fd = open(PIPE_NAME, O_WRONLY);
    if (fd == -1) {
        log(strerror(errno));
        std::string rm = "rm ";
        rm.append(pipe_name);
        system(rm.c_str());
        delete(log_string);
        write(fd, "EXIT", 5);
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
            std::thread t(clientHandler, clientSocket, ipstr);
            t.detach();
        }
    }
    return 0;
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

void clientHandler(int clientSocket, const char* ipstr) {
    char buffer[10];
    std::size_t sz = 10;
    bool exit = false;
    while (!exit) {
        std::string tmp = "Client from ";
        tmp.append(ipstr); 
        int rc = recv(clientSocket, buffer, 10, 0);
        int flag = std::stoi(buffer, &sz, 10);
        if (rc < 0)
            log("Error with reading data from client\\n");
        else {
            int swap_response, free_swap_bytes_response;
            std::string response;
            switch (flag) {
                case GET_SWAP_SIZE: 
                    swap_response = getSwapSize(); 
                    tmp.append(" ask swap size: ");
                    if (swap_response == -1) response = "error to get swap size";
                    else response = std::to_string(swap_response);
                    tmp.append(response);
                    tmp.push_back('\n');
                    log(tmp.c_str());
                    send(clientSocket, response.c_str(), response.length(), MSG_NOSIGNAL);
                    break;
                case GET_FREE_SWAP_BYTES: 
                    free_swap_bytes_response = getFreeSwapBytes();
                    tmp.append(" ask free swap bytes: ");
                    if (free_swap_bytes_response == -1) response = "error to get free swap bytes";
                    else response = std::to_string(free_swap_bytes_response);
                    tmp.append(response);
                    tmp.push_back('\n');
                    log(tmp.c_str());
                    send(clientSocket, response.c_str(), response.length(), MSG_NOSIGNAL);
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

int getSwapSize() {
    long long res;
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        std::cerr << "Error getting swap size" << std::endl;
        res = -1;
    } else
        res = (long long)info.totalswap * (long long)info.mem_unit;
    return res;
}

int getFreeSwapBytes() {
    long long res;
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        std::cerr << "Error getting swap size" << std::endl;
        res = -1;
    } else
        res = (long long)info.freeswap * (long long)info.mem_unit;
    return res;
}
