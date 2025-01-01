cmake_minimum_required(VERSION 3.15)
project(file_io CXX)

find_package(file_types CONFIG REQUIRED)

add_library(file_io src/file_io.cpp)
target_include_directories(file_io PUBLIC include)
target_link_libraries(file_io PRIVATE file_types::file_types)


set_target_properties(file_io PROPERTIES PUBLIC_HEADER "include/file_io.h")
install(TARGETS file_io)
