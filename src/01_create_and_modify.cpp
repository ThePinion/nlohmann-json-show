#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    // create an empty structure (null)
    json j1;

    // implicit conversion of j to an object
    j1["pi"] = 3.141;
    j1["happy"] = true;
    j1["name"] = "Niels";
    j1["nothing"] = nullptr;
    j1["answer"]["everything"] = 42;
    j1["list"] = { 1, 0, 2 };
    j1["object"] = { {"currency", "USD"}, {"value", 42.99} };
    
    std::cout << j1.dump(4) << std::endl;

    json j2 = {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {"answer", {
            {"everything", 42}
        }},
        {"list", {1, 0, 2}},
        {"object", {
            {"currency", "USD"},
            {"value", 42.99}
        }}
    };

    // Modify
    j2["new"]["key"] = {"another", "list"};
    
    std::cout << j2.dump(4) << std::endl;

    return 0;
}
