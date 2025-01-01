cmake_minimum_required(VERSION 3.15)
project(common CXX)




add_library(common src/common.cpp)
target_include_directories(common PUBLIC include)



set_target_properties(common PROPERTIES PUBLIC_HEADER "include/common.h")
install(TARGETS common)
