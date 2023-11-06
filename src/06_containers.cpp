#include <iostream>
#include <vector>
#include <map>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    json numbers_json = numbers;

    std::cout << "JSON array from vector: " << numbers_json.dump() << std::endl;

    std::map<std::string, int> age_map = {
        {"Alice", 30},
        {"Bob", 25},
        {"Carol", 33}
    };

    json age_map_json = age_map;

    std::cout << "JSON object from map: " << age_map_json.dump(4) << std::endl;

    auto numbers_vector = numbers_json.get<std::vector<int>>();
    auto age_map_copy = age_map_json.get<std::map<std::string, int>>();

    return 0;
}
