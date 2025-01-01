#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define SUPER_EXPORT __declspec(dllexport)
#else
  #define SUPER_EXPORT
#endif

SUPER_EXPORT void super();
SUPER_EXPORT void super_print_vector(const std::vector<std::string> &strings);
