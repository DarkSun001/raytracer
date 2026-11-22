#pragma once

#include "raytracer/colour.h"

namespace raytracer {

// A shape *has a* Material: composition over inheritance.
// See docs/adr/0002-shape-owns-material.md.
struct Material {
    Colour colour;
};

} // namespace raytracer
