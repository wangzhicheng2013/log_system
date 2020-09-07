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
#define LOG_INFO(format_str, ...) { auto str = std::move(G_STRING_UTILITY.get_format_str(format_str, __VA_ARGS__)); \
                                    LOG4CXX_INFO(G_LOG_FILE, str.c_str()); }

#define LOG_DEBUG(format_str, ...) { auto str = std::move(G_STRING_UTILITY.get_format_str(format_str, __VA_ARGS__)); \
                                    LOG4CXX_DEBUG(G_LOG_FILE, str.c_str()); }

#define LOG_WARN(format_str, ...) { auto str = std::move(G_STRING_UTILITY.get_format_str(format_str, __VA_ARGS__)); \
                                    LOG4CXX_WARN(G_LOG_FILE, str.c_str()); }

#define LOG_ERROR(format_str, ...) { auto str = std::move(G_STRING_UTILITY.get_format_str(format_str, __VA_ARGS__)); LOG4CXX_ERROR(G_LOG_FILE, str.c_str()); }