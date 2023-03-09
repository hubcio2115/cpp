#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}

    Point(const Point &point) {
        x = point.x;
        y = point.y;
    };

    [[nodiscard]] std::string toString() const {
        return "x: " + std::to_string(x) + ", " + "y: " + std::to_string(y);
    }

    Point operator+(const Point &arg) const {
        return Point{x + arg.x, y + arg.y};
    }

    Point operator++() const {
        return Point{this->x + 1, this->y + 1};
    }

    Point operator++(int) const {
        return Point{this->x + 1, this->y + 1};
    }

    bool operator==(const Point &arg) const {
        return x == arg.x && y == arg.y;
    }

    bool operator>(const Point &arg) const {
        return x > arg.x && y > arg.y;
    }

    bool operator>=(const Point &arg) const {
        return this > &arg && this == &arg;
    }
};

//int main() {
//    Point point1{10, 11};
//    const Point &point2 = point1;
//
//    Point point3 = point1 + point2;
//    printf("%s\n", point3.toString().c_str());
//
//    ++point3;
//    printf("%s\n", point3.toString().c_str());
//
//    point3++;
//    printf("%s\n", point3.toString().c_str());
//
//    printf("%i\n", point3 > point2);
//}
