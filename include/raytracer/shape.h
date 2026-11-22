#pragma once

#include <optional>

#include "raytracer/hit.h"
#include "raytracer/ray.h"

namespace raytracer {

// Abstract over geometry so Scene can hold heterogeneous shapes
// and dispatch intersection tests polymorphically.
class Shape {
public:
    virtual ~Shape() = default;
    virtual std::optional<Hit> intersect(const Ray& ray) const = 0;
};

} // namespace raytracer
