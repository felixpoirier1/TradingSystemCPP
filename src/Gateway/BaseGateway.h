#pragma once
#include <string>

class BaseGateway{
    std::string NAME = "BaseGateway";
    std::string _DB_PATH = "data/data.db";

public:
    virtual void setLogger() = 0;
    virtual void beginStream() = 0;
    virtual void endStream() = 0;
};
