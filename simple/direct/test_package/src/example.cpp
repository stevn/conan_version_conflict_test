#include "direct.h"
#include <vector>
#include <string>

int main() {
    direct();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    direct_print_vector(vec);
}
