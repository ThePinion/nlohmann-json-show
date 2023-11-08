#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    json j = {
        {"foo", "bar"},
        {"baz", "qux"},
        {"list", {1, 2, {{"val", "nested value"}}}}
    };

    json::json_pointer ptr("/foo");
    std::cout << j[ptr] << std::endl; // Outputs "bar"
    
    // Outputs "nested value"
    std::cout << j[json::json_pointer("/list/2/val")] << std::endl; 

    // Change the value using the pointer
    j[ptr] = "new value";
    std::cout << j.dump(4) << std::endl;

    return 0;
}
