#include "IBFIXGateway.h"
#include "../utils/Logger.h"
#include <thread>
#include <boost/log/trivial.hpp>

void IBFIXGateway::setLogger(){
    Logger logger(std::this_thread::get_id());
    logger.setLogger(boost::log::trivial::info);
}