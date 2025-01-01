#include "super.h"
#include <vector>
#include <string>

int main() {
    super();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    super_print_vector(vec);
}
