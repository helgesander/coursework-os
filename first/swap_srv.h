//
// Created by helge on 20.11.2023.
//

#ifndef JULIA_COURSEWORK_SWAP_SRV_H
#define JULIA_COURSEWORK_SWAP_SRV_H

#include <iostream>
#include <windows.h>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

#define PORT 27015
#define HOST "127.0.0.1"

void send_log_information(std::string);
void get_swap_size_and_free_bytes();

#endif //JULIA_COURSEWORK_SWAP_SRV_H
