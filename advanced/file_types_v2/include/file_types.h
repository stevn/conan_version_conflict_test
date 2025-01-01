#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define FILE_TYPES_EXPORT __declspec(dllexport)
#else
  #define FILE_TYPES_EXPORT
#endif

FILE_TYPES_EXPORT void file_types_v2();
FILE_TYPES_EXPORT void file_types_print_vector_v2(const std::vector<std::string> &strings);
