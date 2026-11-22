#include "raytracer/colour.h"

#include <algorithm>
#include <cstdint>

namespace raytracer {

namespace {
double clamp01(double value) {
    return std::min(1.0, std::max(0.0, value));
}
unsigned char to_byte(double channel) {
    return static_cast<unsigned char>(clamp01(channel) * 255.0 + 0.5);
}
} // namespace

Colour::Colour() : r_(0.0), g_(0.0), b_(0.0) {}

Colour::Colour(double r, double g, double b) : r_(r), g_(g), b_(b) {}

Colour Colour::operator+(const Colour& other) const {
    return Colour(r_ + other.r_, g_ + other.g_, b_ + other.b_);
}

Colour Colour::operator*(double scalar) const {
    return Colour(r_ * scalar, g_ * scalar, b_ * scalar);
}

Colour Colour::operator*(const Colour& other) const {
    return Colour(r_ * other.r_, g_ * other.g_, b_ * other.b_);
}

RgbByte Colour::to_bytes() const {
    return RgbByte{to_byte(r_), to_byte(g_), to_byte(b_)};
}

} // namespace raytracer
