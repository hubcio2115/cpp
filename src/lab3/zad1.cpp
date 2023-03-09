#include <iostream>

class Vector {
public:
    int X;
    int Y;
    int Z;

    Vector(int x, int y, int z) : X(x), Y(y), Z(z) {}

    Vector operator+(const Vector &vector) const {
        return Vector{X + vector.X, Y + vector.Y, Z + vector.Z};
    }

    Vector operator-(const Vector &vector) const {
        return Vector{X - vector.X, Y - vector.Y, Z - vector.Z};
    }

    void operator++() {
        X++;
        Y++;
        Z++;
    }

    bool operator==(const Vector &vector) const {
        return X == vector.X && Y == vector.Y && Z == vector.Z;
    }

    bool operator!=(const Vector &vector) const {
        return X != vector.X && Y != vector.Y && Z != vector.Z;
    }

    [[nodiscard]] std::string toString() const {
        return "X: " + std::to_string(X) + ", Y: " + std::to_string(Y) + ", Z: " + std::to_string(Z);
    }

    Vector operator*(const Vector &vector) const {
        return Vector{
                Y * vector.Z - Z * vector.Y,
                Z * vector.X - X * vector.Z,
                X * vector.Y - Y * vector.X
        };
    }
};

int main() {
    auto vector1 = Vector{1, 2, 3};
    auto vector2 = Vector{3, 4, 5};

    printf("wektor1: %s\n", vector1.toString().c_str());
    printf("wektor2: %s\n", vector2.toString().c_str());

    auto vector3 = vector1 + vector2;
    printf("wektor3: %s\n", vector3.toString().c_str());

    ++vector3;
    printf("wektor3: %s\n", vector3.toString().c_str());

    auto vector4 = vector2 - vector1;
    printf("wektor4: %s\n", vector4.toString().c_str());

    auto vector5 = vector1 * vector2;
    printf("wektor5: %s\n", vector5.toString().c_str());

    printf("%i\n", vector2 == vector1);
    printf("%i\n", vector2 != vector1);
}
