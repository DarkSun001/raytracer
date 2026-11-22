#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "raytracer/colour.h"
#include "raytracer/plane.h"

using namespace raytracer;
using Catch::Approx;

namespace {
Material make_material() {
    return Material{Colour(0.0, 1.0, 0.0)};
}
}

TEST_CASE("Ray straight down hits the ground plane", "[plane]") {
    const Plane plane(Vector(0.0, -1.0, 0.0), Vector(0.0, 1.0, 0.0), make_material());
    const Ray ray(Vector(0.0, 2.0, 0.0), Vector(0.0, -1.0, 0.0));

    const auto hit = plane.intersect(ray);

    REQUIRE(hit.has_value());
    REQUIRE(hit->t == Approx(3.0));
    REQUIRE(hit->point == Vector(0.0, -1.0, 0.0));
}

TEST_CASE("Ray parallel to the plane never hits it", "[plane]") {
    const Plane plane(Vector(0.0, -1.0, 0.0), Vector(0.0, 1.0, 0.0), make_material());
    const Ray ray(Vector(0.0, 2.0, 0.0), Vector(1.0, 0.0, 0.0));

    REQUIRE_FALSE(plane.intersect(ray).has_value());
}

TEST_CASE("Ray pointing away from the plane does not hit it", "[plane]") {
    const Plane plane(Vector(0.0, -1.0, 0.0), Vector(0.0, 1.0, 0.0), make_material());
    const Ray ray(Vector(0.0, 2.0, 0.0), Vector(0.0, 1.0, 0.0));

    REQUIRE_FALSE(plane.intersect(ray).has_value());
}

TEST_CASE("Plane normal is normalized even if constructed with a longer vector", "[plane]") {
    const Plane plane(Vector(0.0, -1.0, 0.0), Vector(0.0, 5.0, 0.0), make_material());
    const Ray ray(Vector(0.0, 2.0, 0.0), Vector(0.0, -1.0, 0.0));

    const auto hit = plane.intersect(ray);

    REQUIRE(hit.has_value());
    REQUIRE(hit->normal.length() == Approx(1.0));
}
