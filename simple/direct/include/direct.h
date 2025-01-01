#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define DIRECT_EXPORT __declspec(dllexport)
#else
  #define DIRECT_EXPORT
#endif

DIRECT_EXPORT void direct();
DIRECT_EXPORT void direct_print_vector(const std::vector<std::string> &strings);
