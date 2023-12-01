// backend.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#define _WINSOCKAPI_
#define _WIN32_WINNT 0x501

#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#include <thread>

#define PORT 12344


int getSwapSize();
int getFreeBytesFromSwap();

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
