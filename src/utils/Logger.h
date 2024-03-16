#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/formatter_parser.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <iostream>
#include <thread>

class Logger{
    std::thread::id _id;
public:
    Logger(std::thread::id id){
        _id = id;
    }
    void setLogger(boost::log::trivial::severity_level level){
        // Set up the logging format
        boost::log::register_simple_formatter_factory<boost::log::trivial::severity_level, char>("Severity");

        // Set up the logging sinks (output destinations)
        boost::log::add_console_log(std::cout,
                                  boost::log::keywords::format = "[%TimeStamp%] [%Severity%] %Message%");
        boost::log::core::get()->set_filter(
            boost::log::trivial::severity >= level
        );
    }
    void beginStream(){
        BOOST_LOG_TRIVIAL(info) << "Thread " << _id << " has started streaming";
    }
    void endStream(){
        BOOST_LOG_TRIVIAL(info) << "Thread " << _id << " has ended streaming";
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