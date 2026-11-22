#pragma once

#include "raytracer/material.h"
#include "raytracer/shape.h"
#include "raytracer/vector.h"

namespace raytracer {

class Plane : public Shape {
public:
    // `point` is any point on the plane, `normal` need not be pre-normalized.
    Plane(const Vector& point, const Vector& normal, const Material& material);

    std::optional<Hit> intersect(const Ray& ray) const override;

private:
    Vector point_;
    Vector normal_;
    Material material_;
};

} // namespace raytracer
