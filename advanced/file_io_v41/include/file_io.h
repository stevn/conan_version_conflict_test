#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define FILE_IO_EXPORT __declspec(dllexport)
#else
  #define FILE_IO_EXPORT
#endif

FILE_IO_EXPORT void file_io();
FILE_IO_EXPORT void file_io_print_vector(const std::vector<std::string> &strings);
