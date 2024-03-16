#pragma once
#include "BaseGateway.h"

class IBFIXGateway : public BaseGateway{
    std::string NAME = "IBFIXGateway";
    std::string _DB_PATH = "data/ibfix.db";
    
public:
    void setLogger();
    void beginStream();
    void endStream();
};