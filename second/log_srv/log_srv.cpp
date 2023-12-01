#include "log_srv.h"

int main() {
    std::ofstream logfile(log_name);
    int fd = open(PIPE_NAME, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        std::cerr << server_name << " " << "Error to open pipe" << std::endl;
        return -1;
    }
    return 0;
}