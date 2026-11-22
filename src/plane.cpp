#include "raytracer/plane.h"

#include <cmath>

namespace raytracer {

namespace {
constexpr double kMinT = 1e-6;
constexpr double kParallelEpsilon = 1e-9;
}

Plane::Plane(const Vector& point, const Vector& normal, const Material& material)
    : point_(point), normal_(normal.normalized()), material_(material) {}

std::optional<Hit> Plane::intersect(const Ray& ray) const {
    const double denom = normal_.dot(ray.direction());
    if (std::abs(denom) < kParallelEpsilon) {
        return std::nullopt;
    }

    const double t = (point_ - ray.origin()).dot(normal_) / denom;
    if (t < kMinT) {
        return std::nullopt;
    }

    const Vector point = ray.point_at(t);
    return Hit{t, point, normal_, material_};
}

} // namespace raytracer
