#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define FILE_MUX_EXPORT __declspec(dllexport)
#else
  #define FILE_MUX_EXPORT
#endif

FILE_MUX_EXPORT void file_mux();
FILE_MUX_EXPORT void file_mux_print_vector(const std::vector<std::string> &strings);
