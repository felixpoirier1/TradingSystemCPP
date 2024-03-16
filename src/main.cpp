#include <iostream>
#include <boost/log/trivial.hpp>

int main(){
    BOOST_LOG_TRIVIAL(info) << "Hello, world!";
    return 0;
}