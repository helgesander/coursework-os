#include "swap_srv.h"

int main() {
    SOCKET socket = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "The server is running" << std::endl;
    return 0;
}

void send_log_information(std::string) {

}
