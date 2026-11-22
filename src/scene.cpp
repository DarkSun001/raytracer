#include "raytracer/scene.h"

namespace raytracer {

Scene::Scene()
    : light_direction_(Vector(0.0, 1.0, 0.0)),
      background_(Colour(0.53, 0.81, 0.92)) {}

void Scene::add(std::unique_ptr<Shape> shape) {
    shapes_.push_back(std::move(shape));
}

void Scene::set_light_direction(const Vector& direction_to_light) {
    light_direction_ = direction_to_light.normalized();
}

void Scene::set_background(const Colour& colour) {
    background_ = colour;
}

std::optional<Hit> Scene::closest_hit(const Ray& ray) const {
    std::optional<Hit> closest;
    for (const auto& shape : shapes_) {
        auto hit = shape->intersect(ray);
        if (hit && (!closest || hit->t < closest->t)) {
            closest = hit;
        }
    }
    return closest;
}

} // namespace raytracer
