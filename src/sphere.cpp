#include "raytracer/sphere.h"

#include <cmath>

namespace raytracer {

namespace {
constexpr double kMinT = 1e-6;
}

Sphere::Sphere(const Vector& center, double radius, const Material& material)
    : center_(center), radius_(radius), material_(material) {}

std::optional<Hit> Sphere::intersect(const Ray& ray) const {
    const Vector oc = ray.origin() - center_;
    const double a = ray.direction().dot(ray.direction());
    const double b = 2.0 * oc.dot(ray.direction());
    const double c = oc.dot(oc) - radius_ * radius_;
    const double discriminant = b * b - 4.0 * a * c;

    if (discriminant < 0.0) {
        return std::nullopt;
    }

    const double sqrt_discriminant = std::sqrt(discriminant);
    const double t0 = (-b - sqrt_discriminant) / (2.0 * a);
    const double t1 = (-b + sqrt_discriminant) / (2.0 * a);

    double t = t0;
    if (t < kMinT) {
        t = t1;
    }
    if (t < kMinT) {
        return std::nullopt;
    }

    const Vector point = ray.point_at(t);
    const Vector normal = (point - center_).normalized();
    return Hit{t, point, normal, material_};
}

} // namespace raytracer
