cmake_minimum_required(VERSION 3.15)
project(direct CXX)

find_package(common CONFIG REQUIRED)



add_library(direct src/direct.cpp)
target_include_directories(direct PUBLIC include)
target_link_libraries(direct common::common)



set_target_properties(direct PROPERTIES PUBLIC_HEADER "include/direct.h")
install(TARGETS direct)
