#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define FILE_TYPES_EXPORT __declspec(dllexport)
#else
  #define FILE_TYPES_EXPORT
#endif

FILE_TYPES_EXPORT void file_types();
FILE_TYPES_EXPORT void file_types_print_vector(const std::vector<std::string> &strings);
