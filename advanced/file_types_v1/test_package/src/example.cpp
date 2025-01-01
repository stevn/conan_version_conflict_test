#include "file_types.h"
#include <vector>
#include <string>

int main() {
    file_types();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    file_types_print_vector(vec);
}
