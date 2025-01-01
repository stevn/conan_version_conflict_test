cmake_minimum_required(VERSION 3.15)
project(file_interface CXX)


find_package(file_types CONFIG REQUIRED)
find_package(file_mux CONFIG REQUIRED)

add_library(file_interface src/file_interface.cpp)
target_include_directories(file_interface PUBLIC include)
target_link_libraries(file_interface PRIVATE
    file_types::file_types
    file_mux::file_mux)


set_target_properties(file_interface PROPERTIES PUBLIC_HEADER "include/file_interface.h")
install(TARGETS file_interface)
