#include "raytracer/shading.h"

#include <algorithm>

namespace raytracer {

double lambert_intensity(const Vector& normal, const Vector& direction_to_light) {
    return std::max(0.0, normal.dot(direction_to_light));
}

} // namespace raytracer
