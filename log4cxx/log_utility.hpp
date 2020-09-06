#pragma once
#include "string_utility.hpp"
#include <log4cxx/logger.h>
#include <log4cxx/propertyconfigurator.h>
using namespace log4cxx;
static LoggerPtr G_LOG_FILE;
class log_utility {
public:
    static bool init(const char *log_conf_file, const char *appender_name) {
        try {
             PropertyConfigurator::configure(log_conf_file);
             G_LOG_FILE = Logger::getLogger(appender_name);
        }
        catch (...) {
            return false;
        }
        return true;
    }
};
#define LOG_INFO(format_str, ...) { auto str = G_STRING_UTILITY.get_format_str(format_str, __VA_ARGS__); \
                                    LOG4CXX_INFO(G_LOG_FILE, str.c_str()); }
