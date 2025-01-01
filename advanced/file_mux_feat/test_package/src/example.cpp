#include "file_mux.h"
#include <vector>
#include <string>

int main() {
    file_mux();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    file_mux_print_vector(vec);
}
