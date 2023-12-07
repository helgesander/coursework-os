#include "log_srv.h"

int main() {
    std::ofstream logfile(log_name);
    int fd = open(PIPE_NAME, O_RDONLY);
    if (fd == -1) {
        std::cerr << server_name << " " << "Error to open pipe" << std::endl;
        return 1;
    }
    bool flag = true;
    char log_info[BUFSIZE];
    std::cout << "Log server start..." << std::endl;
    while(flag) {
        read(fd, log_info, BUFSIZE);
        std::cout << log_info;
        logfile << log_info;
    }
    return 0;
}
