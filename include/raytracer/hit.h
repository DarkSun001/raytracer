#pragma once

#include "raytracer/material.h"
#include "raytracer/vector.h"

namespace raytracer {

struct Hit {
    double t;
    Vector point;
    Vector normal;
    Material material;
};

} // namespace raytracer
