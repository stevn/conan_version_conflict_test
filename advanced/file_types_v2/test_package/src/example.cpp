#include "file_types.h"
#include <vector>
#include <string>

int main() {
    file_types_v2();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    file_types_print_vector_v2(vec);
}
