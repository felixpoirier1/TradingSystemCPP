cmake_minimum_required(VERSION 3.1)
project(trading_system_cpp)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the default location where Boost will be installed
set(BOOST_INSTALL_DIR ${CMAKE_BINARY_DIR}/boost_install)

# Find Boost
find_package(Boost REQUIRED COMPONENTS log)

# If Boost is not found, download and build it
if(NOT Boost_FOUND)
    message(STATUS "Boost not found. Downloading and building...")

    ExternalProject_Add(
        boost
        PREFIX ${BOOST_INSTALL_DIR}
        URL https://dl.bintray.com/boostorg/release/1.77.0/source/boost_1_77_0.tar.gz
        URL_HASH SHA256=5347464af5b14ac54bb945dc68f1dd7c56f0dad7262816b956138fc53bcc0131
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ./bootstrap.sh --prefix=${BOOST_INSTALL_DIR} --with-libraries=all
        BUILD_IN_SOURCE TRUE
        INSTALL_COMMAND ./b2 install
    )

    # Specify include and library directories for Boost
    ExternalProject_Get_Property(boost source_dir)
    set(BOOST_INCLUDE_DIRS ${source_dir})
    set(BOOST_LIBRARY_DIRS ${BOOST_INSTALL_DIR}/lib)
    set(Boost_LIBRARIES 
        ${BOOST_INSTALL_DIR}/lib/libboost_log.a
        ${BOOST_INSTALL_DIR}/lib/libboost_log_setup.a
    )

    # Add Boost include directories
    include_directories(${BOOST_INCLUDE_DIRS})
else()
    # If Boost is found, use the found Boost variables
    include_directories(${Boost_INCLUDE_DIRS})
    set(BOOST_INCLUDE_DIRS ${Boost_INCLUDE_DIRS})
    set(BOOST_LIBRARY_DIRS ${Boost_LIBRARY_DIRS})
    set(Boost_LIBRARIES ${Boost_LIBRARIES})
endif()

# Now, you can use Boost_LIBRARIES, BOOST_INCLUDE_DIRS, and BOOST_LIBRARY_DIRS in your project
# For example:
add_executable(trading_system.app src/main.cpp)

# Include Boost headers
target_include_directories(trading_system.app PRIVATE ${Boost_INCLUDE_DIRS})

# Link against Boost.Log
target_link_libraries(trading_system.app PRIVATE Boost::log)
