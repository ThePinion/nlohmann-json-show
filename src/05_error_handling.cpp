#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    try {
        // Try to parse invalid JSON               ↓here  
        std::string invalid_json = R"({"name": "John, "age": 30})"; // Missing quote after "John
        json parsed_json = json::parse(invalid_json);
    } catch (json::parse_error& e) {
        std::cerr << "Parse error: " << e.what() << "\n\n";
    }

    try {
        // Accessing a non-existing key
        json j = {{"name", "John"}, {"age", 30}};
        std::cout << j.at("address") << '\n'; 
    } catch (json::out_of_range& e) {
        std::cerr << "Accessing non-existing key: " << e.what() << "\n\n";
    }

    try {
        // Type error: trying to get a string from an integer
        json j = {{"age", 30}};
        std::string age = j.at("age").get<std::string>(); // age is not a string
    } catch (json::type_error& e) {
        std::cerr << "Type error: " << e.what() << "\n\n\n";
    }

    json j_invalid = "ä\xA9ü";
    try
    {
        std::cout << j_invalid.dump() << std::endl;
    }
    catch (const json::type_error& e)
    {
        std::cout << e.what() << "\n\n";
    }

    

    std::cout << "replaced: "
              << j_invalid.dump(-1, ' ', false, json::error_handler_t::replace)
              << "\nignored: "
              << j_invalid.dump(-1, ' ', false, json::error_handler_t::ignore)
              << std::endl;

    return 0;
}
