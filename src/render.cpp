#include "raytracer/render.h"

#include "raytracer/shading.h"

namespace raytracer {

namespace {
constexpr double kAmbient = 0.1;
}

Colour trace(const Ray& ray, const Scene& scene) {
    const auto hit = scene.closest_hit(ray);
    if (!hit) {
        return scene.background();
    }

    const double intensity = kAmbient + (1.0 - kAmbient) * lambert_intensity(hit->normal, scene.light_direction());
    return hit->material.colour * intensity;
}

Image render(const Scene& scene, const Camera& camera, int width, int height) {
    Image image(width, height);
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            const Ray ray = camera.ray_for_pixel(col, row, width, height);
            image.set(col, row, trace(ray, scene));
        }
    }
    return image;
}

} // namespace raytracer
