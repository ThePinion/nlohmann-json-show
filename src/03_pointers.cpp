#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    json j = {
        {"foo", "bar"},
        {"baz", "qux"}
    };

    json::json_pointer ptr("/foo");
    std::cout << j[ptr] << std::endl; // Outputs "bar"

    // Change the value using the pointer
    j[ptr] = "new value";
    std::cout << j.dump(4) << std::endl;

    return 0;
}
