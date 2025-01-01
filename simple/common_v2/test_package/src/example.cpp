#include "common.h"
#include <vector>
#include <string>

int main() {
    common_v2();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    common_print_vector_v2(vec);
}
