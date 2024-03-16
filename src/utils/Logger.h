#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <iostream>
#include <thread>

class Logger{
public:
    void setLogger() {
        // Set the log signature
        boost::log::add_common_attributes();
    }
    void beginStream(){
        BOOST_LOG_TRIVIAL(info) << "Thread has started streaming";
        BOOST_LOG_TRIVIAL(debug) << "Attempting to connect to the server";

    }
    void endStream(){
        BOOST_LOG_TRIVIAL(info) << "Thread has ended streaming";
    }
    void logTrace(const std::string& message) {
        BOOST_LOG_TRIVIAL(trace) << message;
    }

    void logDebug(const std::string& message) {
        BOOST_LOG_TRIVIAL(debug) << message;
    }

    void logInfo(const std::string& message) {
        BOOST_LOG_TRIVIAL(info) << message;
    }

    void logWarning(const std::string& message) {
        BOOST_LOG_TRIVIAL(warning) << message;
    }

    void logError(const std::string& message) {
        BOOST_LOG_TRIVIAL(error) << message;
    }

    void logFatal(const std::string& message) {
        BOOST_LOG_TRIVIAL(fatal) << message;
    }
};