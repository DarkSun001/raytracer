#pragma once

#include "raytracer/vector.h"

namespace raytracer {

// Lambert's law: a surface reflects light proportionally to the cosine
// of the angle between its normal and the direction to the light.
// Both vectors must be normalized. Returns 0 when the surface faces away.
double lambert_intensity(const Vector& normal, const Vector& direction_to_light);

} // namespace raytracer
