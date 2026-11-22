#pragma once

namespace raytracer {

class Vector {
public:
    Vector();
    Vector(double x, double y, double z);

    double x() const { return x_; }
    double y() const { return y_; }
    double z() const { return z_; }

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator-() const;
    Vector operator*(double scalar) const;

    double dot(const Vector& other) const;
    double length() const;
    Vector normalized() const;

    bool operator==(const Vector& other) const;

private:
    double x_;
    double y_;
    double z_;
};

Vector operator*(double scalar, const Vector& v);

} // namespace raytracer
