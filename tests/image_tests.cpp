#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "raytracer/image.h"

using namespace raytracer;
using Catch::Approx;

TEST_CASE("Image stores and retrieves the colour set at a pixel", "[image]") {
    Image image(4, 3);
    image.set(2, 1, Colour(0.5, 0.25, 0.75));

    const Colour& colour = image.get(2, 1);

    REQUIRE(colour.r() == Approx(0.5));
    REQUIRE(colour.g() == Approx(0.25));
    REQUIRE(colour.b() == Approx(0.75));
}

TEST_CASE("Image exposes the dimensions it was constructed with", "[image]") {
    Image image(400, 300);
    REQUIRE(image.width() == 400);
    REQUIRE(image.height() == 300);
}

TEST_CASE("Unset pixels default to black", "[image]") {
    Image image(2, 2);
    const Colour& colour = image.get(0, 0);
    REQUIRE(colour.r() == Approx(0.0));
    REQUIRE(colour.g() == Approx(0.0));
    REQUIRE(colour.b() == Approx(0.0));
}
