#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    // Parse JSON from a string
    std::string str = R"({"happy": true, "pi": 3.141})";
    json j = json::parse(str);

    // Change a value
    j["happy"] = false;

    // Serialize to string
    std::string serialized = j.dump(4);  
    std::cout << serialized << std::endl;
    
    std::cout << j.dump() << std::endl; // Compact output

    std::ofstream file("output.json");
    file << j.dump(4);
    file.close();

    return 0;
}
