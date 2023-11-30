#include "backend.h"

std::pair<int, int> getScreensize();
int getProcessTime();
void clientHandler(int clientSocket);

int main() {
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientStructLen;
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return -1;
    }
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(12345);
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error with binding socket" << std::endl;
        return -1;
    }
    listen(serverSocket, 5);
    while (true)
    {
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientStructLen);
        if (clientSocket < 0) {
            std::cerr << "Error with connection for server" << std::endl;
            continue;
        } else std::cout << "Connect uhu" << std::endl;
        std::thread t(clientHandler, clientSocket);
        t.detach();
    }
    close(serverSocket);
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
    } else {
        if (flag != GET_PROCESS_TIME && flag != GET_SCREENSIZE)
            std::cerr << "bad choice" << std::endl;
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