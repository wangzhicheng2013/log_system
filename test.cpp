#include <iostream>
#include <thread>
#include "nanolog.hpp"
void fun0() {
    for (int i = 0;i < 10;i++) {
        LOG_INFO << "INFO";
    }
}
void fun1() {
    for (int i = 0;i < 10;i++) {
        LOG_CRIT << "CRIT";
    }
}
int main() {
    nanolog::initialize(nanolog::GuaranteedLogger(), "./", "22.log", 1);    // 1M
    nanolog::set_log_level(nanolog::LogLevel::INFO);
    std::thread th0(fun0);
    std::thread th1(fun1);
    th0.join();
    th1.join();

    return 0;
}