#include "raytracer/vector.h"

#include <cmath>

namespace raytracer {

namespace {
constexpr double kEpsilon = 1e-9;
}

Vector::Vector() : x_(0.0), y_(0.0), z_(0.0) {}

Vector::Vector(double x, double y, double z) : x_(x), y_(y), z_(z) {}

Vector Vector::operator+(const Vector& other) const {
    return Vector(x_ + other.x_, y_ + other.y_, z_ + other.z_);
}

Vector Vector::operator-(const Vector& other) const {
    return Vector(x_ - other.x_, y_ - other.y_, z_ - other.z_);
}

Vector Vector::operator-() const {
    return Vector(-x_, -y_, -z_);
}

Vector Vector::operator*(double scalar) const {
    return Vector(x_ * scalar, y_ * scalar, z_ * scalar);
}

double Vector::dot(const Vector& other) const {
    return x_ * other.x_ + y_ * other.y_ + z_ * other.z_;
}

double Vector::length() const {
    return std::sqrt(dot(*this));
}

Vector Vector::normalized() const {
    const double len = length();
    if (len < kEpsilon) {
        return Vector(0.0, 0.0, 0.0);
    }
    return Vector(x_ / len, y_ / len, z_ / len);
}

bool Vector::operator==(const Vector& other) const {
    return std::abs(x_ - other.x_) < kEpsilon &&
           std::abs(y_ - other.y_) < kEpsilon &&
           std::abs(z_ - other.z_) < kEpsilon;
}

Vector operator*(double scalar, const Vector& v) {
    return v * scalar;
}

} // namespace raytracer
