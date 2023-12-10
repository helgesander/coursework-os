#pragma once

#define _WINSOCKAPI_
#define _WIN32_WINNT 0x501

#pragma comment(lib, "Ws2_32.lib")

#include <cstdlib>
#include <Windows.h>
#include <WinSock2.h>
#include <string>

#define FIRST_PORT 12344
#define SECOND_PORT 12345

extern SOCKET firstClientSocket;
extern SOCKET secondClientSocket;

using namespace System::Runtime::InteropServices;
using namespace System;

bool connectionToServers(char* ip_addr, String^% err);
void closeConnection();

#pragma endregion

