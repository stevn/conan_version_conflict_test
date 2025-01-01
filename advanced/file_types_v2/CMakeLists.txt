cmake_minimum_required(VERSION 3.15)
project(file_types CXX)




add_library(file_types src/file_types.cpp)
target_include_directories(file_types PUBLIC include)



set_target_properties(file_types PROPERTIES PUBLIC_HEADER "include/file_types.h")
install(TARGETS file_types)
