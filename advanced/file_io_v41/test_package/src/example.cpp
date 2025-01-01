#include "file_io.h"
#include <vector>
#include <string>

int main() {
    file_io();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    file_io_print_vector(vec);
}
