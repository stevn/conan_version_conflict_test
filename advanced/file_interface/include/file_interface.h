#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define FILE_INTERFACE_EXPORT __declspec(dllexport)
#else
  #define FILE_INTERFACE_EXPORT
#endif

FILE_INTERFACE_EXPORT void file_interface();
FILE_INTERFACE_EXPORT void file_interface_print_vector(const std::vector<std::string> &strings);
