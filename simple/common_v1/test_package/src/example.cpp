#include "common.h"
#include <vector>
#include <string>

int main() {
    common();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    common_print_vector(vec);
}
