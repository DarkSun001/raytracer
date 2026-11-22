#pragma once

#include <memory>
#include <optional>
#include <vector>

#include "raytracer/colour.h"
#include "raytracer/hit.h"
#include "raytracer/ray.h"
#include "raytracer/shape.h"
#include "raytracer/vector.h"

namespace raytracer {

class Scene {
public:
    Scene();

    void add(std::unique_ptr<Shape> shape);
    void set_light_direction(const Vector& direction_to_light);
    void set_background(const Colour& colour);

    std::optional<Hit> closest_hit(const Ray& ray) const;
    const Vector& light_direction() const { return light_direction_; }
    const Colour& background() const { return background_; }

private:
    std::vector<std::unique_ptr<Shape>> shapes_;
    Vector light_direction_;
    Colour background_;
};

} // namespace raytracer
