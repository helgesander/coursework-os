#include "client.h"

SOCKET firstClientSocket;
SOCKET secondClientSocket;
WSADATA WSAData;

bool connectionToServers(char* ip_addr, String^% err) {
    SOCKADDR_IN firstServerAddr, secondServerAddr;
    WSAStartup(MAKEWORD(2, 0), &WSAData);
    char buffer[1024] = { 0 };
    if (inet_addr(ip_addr) == INADDR_NONE) {
        err = L"������������ ������ IP ������!";
        return true;
    }
    if ((firstClientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        err = L"�������� ��� �������� ������ ��� ������� �������";
        return true;
    }
    else if ((secondClientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        err = L"�������� ��� �������� ������ ��� ������� �������";
        return true;
    }
    firstServerAddr.sin_family = AF_INET;
    firstServerAddr.sin_addr.s_addr = inet_addr(ip_addr);
    firstServerAddr.sin_port = htons(FIRST_PORT);

    secondServerAddr.sin_family = AF_INET;
    secondServerAddr.sin_addr.s_addr = inet_addr(ip_addr);
    secondServerAddr.sin_port = htons(SECOND_PORT);
    if (connect(firstClientSocket, (SOCKADDR*)&firstServerAddr, sizeof(firstServerAddr)) < 0) {
        err = L"�������� � ������������ � ������� �������";
        return true;
    }
    else if (connect(secondClientSocket, (SOCKADDR*)&secondServerAddr, sizeof(secondServerAddr)) < 0) {
        err = L"�������� � ������������ �� ������� �������";
        return true;
    }
    return false;
}

void closeConnection() {
    send(firstClientSocket, "0", 2, 0);
    send(secondClientSocket, "0", 2, 0);
    shutdown(firstClientSocket, SD_BOTH);
    shutdown(secondClientSocket, SD_BOTH);
    closesocket(firstClientSocket);
    closesocket(secondClientSocket);
    WSACleanup();
}
