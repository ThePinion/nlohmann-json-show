#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

// A simple struct representing a person
struct Person {
    std::string name;
    int age;
    std::string occupation;

    json to_json() const {
        return json{{"name", name}, {"age", age}, {"occupation", occupation}};
    }

    static Person from_json(const json& j) {
        return {
            j.at("name").get<std::string>(),
            j.at("age").get<int>(),
            j.at("occupation").get<std::string>()
        };
    }
};

void to_json(json& j, const Person& p) {
    j = p.to_json();
}

void from_json(const json& j, Person& p) {
    p = Person::from_json(j);
}

int main() {
    Person alice{"Alice", 30, "Software Developer"};

    json j = alice;
    std::cout << "Serialized JSON:\n" << j.dump(4) << std::endl;

    Person new_person = j.get<Person>();
    std::cout << "Deserialized Person:\n"
              << "Name: " << new_person.name << "\n"
              << "Age: " << new_person.age << "\n"
              << "Occupation: " << new_person.occupation << std::endl;

    return 0;
}
