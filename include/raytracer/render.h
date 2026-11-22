#pragma once

#include "raytracer/camera.h"
#include "raytracer/colour.h"
#include "raytracer/image.h"
#include "raytracer/ray.h"
#include "raytracer/scene.h"

namespace raytracer {

// Resolves the colour seen along `ray`: the closest shape's shaded colour,
// or the scene's background colour if nothing is hit.
Colour trace(const Ray& ray, const Scene& scene);

// Shoots one ray per pixel through `camera` and traces it against `scene`.
Image render(const Scene& scene, const Camera& camera, int width, int height);

} // namespace raytracer
