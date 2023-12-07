#include "backend.h"

int main() {
    std::cout << getSwapSize() << std::endl;
    return 0;
}


int getSwapSize() {
    long long res;
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        std::cerr << "Error getting swap size" << std::endl;
        res = -1;
    } else
        res = (long long)info.totalswap * (long long)info.mem_unit;
    return res;
}
