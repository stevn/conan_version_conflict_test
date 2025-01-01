#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define COMMON_EXPORT __declspec(dllexport)
#else
  #define COMMON_EXPORT
#endif

COMMON_EXPORT void common_v2();
COMMON_EXPORT void common_print_vector_v2(const std::vector<std::string> &strings);
