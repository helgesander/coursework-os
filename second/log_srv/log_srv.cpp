#include "log_srv.h"

int main() {
    std::cout << "Log server start..." << std::endl;
    std::ofstream logfile(log_name);
    int fd = open(PIPE_NAME, O_RDONLY);
    while (fd == -1) {
        std::cout << "Error to open pipe, retry in 5 seconds..." << std::endl; 
        // logfile << log_name<< " " << "Error to open pipe, retry in 5 seconds..." << std::endl;
        sleep(5);
        fd = open(PIPE_NAME, O_RDONLY);
    }
    bool flag = true;
    while(flag) { 
        char log_info[BUFSIZE] = {0};
        read(fd, log_info, BUFSIZE);
        std::cout << log_info << std::endl;
        if (!strcmp(log_info, "EXIT")) {
            logfile << server_name << " " << "Log server is shutdown" << std::endl; 
            flag = false;
        } else {
            std::time_t now = std::time(0);
            std::tm* localTime = std::localtime(&now);
            std::string time_for_print = std::asctime(localTime);
            time_for_print.pop_back();
            logfile << "[" <<  time_for_print << "] " << log_info;
            //std::cout << log_info;
        }
    }
    return 0;
}
