#include "Gateway/BaseGateway.h"
#include "utils/Logger.h"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <iostream>
#include <thread>

void beginT1(){
    Logger logger;
    logger.setLogger();
    logger.beginStream();
    logger.logInfo("Hello from t1");
    logger.endStream();
}

int main(){
    // Set the severity level
    boost::log::trivial::severity_level level = boost::log::trivial::debug;
    // Set the severity level filter
    boost::log::core::get()->set_filter(
        boost::log::trivial::severity >= level
    );

    std::thread t1(beginT1);

    Logger logger;
    logger.setLogger();
    logger.beginStream();
    logger.logInfo("Hello from main");
    logger.endStream();
    t1.join();
    return 0;
}