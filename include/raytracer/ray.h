#pragma once

#include "raytracer/vector.h"

namespace raytracer {

class Ray {
public:
    Ray(const Vector& origin, const Vector& direction)
        : origin_(origin), direction_(direction) {}

    const Vector& origin() const { return origin_; }
    const Vector& direction() const { return direction_; }

    Vector point_at(double t) const { return origin_ + direction_ * t; }

private:
    Vector origin_;
    Vector direction_;
};

} // namespace raytracer
