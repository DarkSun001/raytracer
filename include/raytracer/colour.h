#pragma once

namespace raytracer {

struct RgbByte {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

class Colour {
public:
    Colour();
    Colour(double r, double g, double b);

    double r() const { return r_; }
    double g() const { return g_; }
    double b() const { return b_; }

    Colour operator+(const Colour& other) const;
    Colour operator*(double scalar) const;
    Colour operator*(const Colour& other) const;

    RgbByte to_bytes() const;

private:
    double r_;
    double g_;
    double b_;
};

} // namespace raytracer
