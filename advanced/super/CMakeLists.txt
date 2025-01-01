cmake_minimum_required(VERSION 3.15)
project(super CXX)

find_package(file_interface CONFIG REQUIRED)
find_package(file_types CONFIG REQUIRED)
find_package(file_mux CONFIG REQUIRED)

add_executable(super src/super.cpp src/main.cpp)
target_link_libraries(super PRIVATE
        file_interface::file_interface
        file_types::file_types
        file_mux::file_mux)


install(TARGETS super DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
