#include "file_interface.h"
#include <vector>
#include <string>

int main() {
    file_interface();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    file_interface_print_vector(vec);
}
