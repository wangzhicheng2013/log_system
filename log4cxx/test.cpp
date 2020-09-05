#include <log4cxx/logger.h>
#include <log4cxx/propertyconfigurator.h>
using namespace log4cxx;
int main() {
    PropertyConfigurator::configure("./test.properties");
    LoggerPtr file = Logger::getLogger("file");
    LOG4CXX_DEBUG(file, "hello DEBUG.");
    LOG4CXX_INFO(file, "hello INFO.");
    LOG4CXX_WARN(file, "hello WARN.");
    LOG4CXX_ERROR(file, "hello ERROR.");
    return 0;
}