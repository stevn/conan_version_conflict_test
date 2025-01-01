cmake_minimum_required(VERSION 3.15)
project(super CXX)

find_package(common CONFIG REQUIRED)
find_package(direct CONFIG REQUIRED)


add_executable(super src/super.cpp src/main.cpp)
target_link_libraries(super PRIVATE common::common)
target_link_libraries(super PRIVATE direct::direct)



install(TARGETS super DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
