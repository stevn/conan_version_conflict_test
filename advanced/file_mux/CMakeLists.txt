cmake_minimum_required(VERSION 3.15)
project(file_mux CXX)

find_package(file_io CONFIG REQUIRED)
find_package(file_types CONFIG REQUIRED)

add_library(file_mux src/file_mux.cpp)
target_include_directories(file_mux PUBLIC include)
target_link_libraries(file_mux PRIVATE
    file_io::file_io
    file_types::file_types)


set_target_properties(file_mux PROPERTIES PUBLIC_HEADER "include/file_mux.h")
install(TARGETS file_mux)
