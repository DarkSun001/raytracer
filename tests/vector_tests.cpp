#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "raytracer/vector.h"

using raytracer::Vector;
using Catch::Approx;

TEST_CASE("Vector addition sums components", "[vector]") {
    const Vector a(1.0, 2.0, 3.0);
    const Vector b(4.0, 5.0, 6.0);
    REQUIRE((a + b) == Vector(5.0, 7.0, 9.0));
}

TEST_CASE("Vector subtraction subtracts components", "[vector]") {
    const Vector a(4.0, 5.0, 6.0);
    const Vector b(1.0, 2.0, 3.0);
    REQUIRE((a - b) == Vector(3.0, 3.0, 3.0));
}

TEST_CASE("Vector scaling multiplies every component", "[vector]") {
    const Vector v(1.0, -2.0, 3.0);
    REQUIRE((v * 2.0) == Vector(2.0, -4.0, 6.0));
}

TEST_CASE("Dot product of perpendicular vectors is zero", "[vector]") {
    const Vector a(1.0, 0.0, 0.0);
    const Vector b(0.0, 1.0, 0.0);
    REQUIRE(a.dot(b) == Approx(0.0));
}

TEST_CASE("Dot product of parallel unit vectors is one", "[vector]") {
    const Vector a(1.0, 0.0, 0.0);
    const Vector b(1.0, 0.0, 0.0);
    REQUIRE(a.dot(b) == Approx(1.0));
}

TEST_CASE("Dot product is negative for opposite vectors", "[vector]") {
    const Vector a(1.0, 0.0, 0.0);
    const Vector b(-1.0, 0.0, 0.0);
    REQUIRE(a.dot(b) < 0.0);
}

TEST_CASE("Length computes the Euclidean norm", "[vector]") {
    const Vector v(3.0, 4.0, 0.0);
    REQUIRE(v.length() == Approx(5.0));
}

TEST_CASE("Normalized vector has unit length", "[vector]") {
    const Vector v(3.0, 4.0, 0.0);
    REQUIRE(v.normalized().length() == Approx(1.0));
}

TEST_CASE("Normalized vector keeps the same direction", "[vector]") {
    const Vector v(0.0, 5.0, 0.0);
    REQUIRE(v.normalized() == Vector(0.0, 1.0, 0.0));
}
