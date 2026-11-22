#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "raytracer/colour.h"
#include "raytracer/render.h"
#include "raytracer/scene.h"
#include "raytracer/shading.h"
#include "raytracer/sphere.h"

using namespace raytracer;
using Catch::Approx;

TEST_CASE("Lambert intensity is maximal when the light faces the surface", "[shading]") {
    const Vector normal(0.0, 0.0, 1.0);
    const Vector light(0.0, 0.0, 1.0);
    REQUIRE(lambert_intensity(normal, light) == Approx(1.0));
}

TEST_CASE("Lambert intensity is zero for perpendicular light", "[shading]") {
    const Vector normal(0.0, 0.0, 1.0);
    const Vector light(1.0, 0.0, 0.0);
    REQUIRE(lambert_intensity(normal, light) == Approx(0.0));
}

TEST_CASE("Lambert intensity never goes negative when light is behind the surface", "[shading]") {
    const Vector normal(0.0, 0.0, 1.0);
    const Vector light(0.0, 0.0, -1.0);
    REQUIRE(lambert_intensity(normal, light) == Approx(0.0));
}

TEST_CASE("Tracing a ray that misses everything returns the background colour", "[render]") {
    Scene scene;
    scene.set_background(Colour(0.1, 0.2, 0.3));
    const Ray ray(Vector(0.0, 0.0, 0.0), Vector(0.0, 1.0, 0.0));

    const Colour colour = trace(ray, scene);

    REQUIRE(colour.r() == Approx(0.1));
    REQUIRE(colour.g() == Approx(0.2));
    REQUIRE(colour.b() == Approx(0.3));
}

TEST_CASE("Tracing a ray that hits a lit sphere returns a shaded colour, not pure background", "[render]") {
    Scene scene;
    scene.set_background(Colour(0.0, 0.0, 0.0));
    scene.add(std::make_unique<Sphere>(Vector(0.0, 0.0, -5.0), 1.0, Material{Colour(1.0, 0.0, 0.0)}));
    scene.set_light_direction(Vector(0.0, 0.0, 1.0));

    const Ray ray(Vector(0.0, 0.0, 0.0), Vector(0.0, 0.0, -1.0));
    const Colour colour = trace(ray, scene);

    REQUIRE(colour.r() > 0.0);
}
