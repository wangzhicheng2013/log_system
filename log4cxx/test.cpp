#include "log_utility.hpp"
int main() {
    if (false == log_utility::init("./test.properties", "file")) {
        return -1;
    }
    LOG_INFO("%s:%d", "Hello, I am a logger", 18);

    return 0;
}