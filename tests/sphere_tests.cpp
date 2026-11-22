#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "raytracer/colour.h"
#include "raytracer/sphere.h"

using namespace raytracer;
using Catch::Approx;

namespace {
Material make_material() {
    return Material{Colour(1.0, 0.0, 0.0)};
}
}

TEST_CASE("Ray through the center hits the near side of the sphere", "[sphere]") {
    const Sphere sphere(Vector(0.0, 0.0, -5.0), 1.0, make_material());
    const Ray ray(Vector(0.0, 0.0, 0.0), Vector(0.0, 0.0, -1.0));

    const auto hit = sphere.intersect(ray);

    REQUIRE(hit.has_value());
    REQUIRE(hit->t == Approx(4.0));
    REQUIRE(hit->point == Vector(0.0, 0.0, -4.0));
}

TEST_CASE("Ray missing the sphere reports no hit", "[sphere]") {
    const Sphere sphere(Vector(0.0, 0.0, -5.0), 1.0, make_material());
    const Ray ray(Vector(0.0, 5.0, 0.0), Vector(0.0, 0.0, -1.0));

    REQUIRE_FALSE(sphere.intersect(ray).has_value());
}

TEST_CASE("Tangent ray grazes the sphere at a single point", "[sphere]") {
    const Sphere sphere(Vector(0.0, 0.0, -5.0), 1.0, make_material());
    const Ray ray(Vector(0.0, 1.0, 0.0), Vector(0.0, 0.0, -1.0));

    const auto hit = sphere.intersect(ray);

    REQUIRE(hit.has_value());
    REQUIRE(hit->t == Approx(5.0));
}

TEST_CASE("Sphere behind the ray origin is not hit", "[sphere]") {
    const Sphere sphere(Vector(0.0, 0.0, 5.0), 1.0, make_material());
    const Ray ray(Vector(0.0, 0.0, 0.0), Vector(0.0, 0.0, -1.0));

    REQUIRE_FALSE(sphere.intersect(ray).has_value());
}

TEST_CASE("Hit normal points outward from the sphere center", "[sphere]") {
    const Sphere sphere(Vector(0.0, 0.0, -5.0), 1.0, make_material());
    const Ray ray(Vector(0.0, 0.0, 0.0), Vector(0.0, 0.0, -1.0));

    const auto hit = sphere.intersect(ray);

    REQUIRE(hit.has_value());
    REQUIRE(hit->normal == Vector(0.0, 0.0, 1.0));
}
