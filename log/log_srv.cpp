#include "log_srv.h"

int main() {
    std::ofstream logfile(log_name, std::ios_base::app);
    logfile << "[" << logTime() << "]" << server_name << " Log server start" << std::endl;
    int fd = open(PIPE_NAME, O_RDONLY);
    size_t count_of_timeouts = 0;
    while (fd == -1) {
        if (count_of_timeouts == 10) {
            logfile << "[" << logTime() << "]" << server_name << " " << "Fatal error to open pipe, exit..." << std::endl;
            logfile.flush();
            return 0;
        }
        logfile << "[" <<  logTime() << "]"<< server_name << " " << "Error to open pipe, retry in 5 seconds..." << std::endl;
        logfile.flush();
        sleep(5);
        count_of_timeouts++;
        fd = open(PIPE_NAME, O_RDONLY);
    }
    while(true) { 
        char log_info[BUFSIZE] = {0};
        read(fd, log_info, BUFSIZE);
        if (!strcmp(log_info, "EXIT")) {
            logfile << "[" <<  logTime() << "]" << server_name << " " << "Log server is shutdown" << std::endl; 
            logfile.flush();
            break;
        } else {
            logfile << "[" <<  logTime() << "]" << log_info;
            logfile.flush();
        }
           
    }
    logfile.close();
    return 0;
}

std::string logTime() {
    std::time_t now = std::time(0);
    std::tm* localTime = std::localtime(&now);
    std::string time_for_print = std::asctime(localTime);
    time_for_print.pop_back();
    return time_for_print;
}
