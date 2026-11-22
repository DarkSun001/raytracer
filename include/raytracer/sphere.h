#pragma once

#include "raytracer/material.h"
#include "raytracer/shape.h"
#include "raytracer/vector.h"

namespace raytracer {

class Sphere : public Shape {
public:
    Sphere(const Vector& center, double radius, const Material& material);

    std::optional<Hit> intersect(const Ray& ray) const override;

private:
    Vector center_;
    double radius_;
    Material material_;
};

} // namespace raytracer
