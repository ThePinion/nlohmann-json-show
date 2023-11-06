#include <iostream>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;

struct Point {
    int x, y;
    json to_json() const {
        return json{{"x", x}, {"y", y}};
    }
    static Point from_json(const json& j) {
        return {j.at("x").get<int>(), j.at("y").get<int>()};
    }
};

void to_json(json& j, const Point& p) {
    j = p.to_json();
}
void from_json(const json& j, Point& p) {
    p = Point::from_json(j);
}

int main() {
    std::vector<Point> points = {{1, 2}, {3, 4}, {5, 6}};

    json points_json = points;

    std::cout << "JSON array from vector of Points: " << points_json.dump(4) << std::endl;

    auto points_vector = points_json.get<std::vector<Point>>();

    for (const auto& point : points_vector) {
        std::cout << "Point: x=" << point.x << ", y=" << point.y << std::endl;
    }

    return 0;
}
