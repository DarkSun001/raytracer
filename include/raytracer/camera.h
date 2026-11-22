#pragma once

#include "raytracer/ray.h"
#include "raytracer/vector.h"

namespace raytracer {

// A simple pinhole camera: a screen plane sits `screen_distance` in front
// of `eye`, spanning `screen_width` x `screen_height` world units.
class Camera {
public:
    Camera(const Vector& eye, double screen_width, double screen_height, double screen_distance);

    Ray ray_for_pixel(int col, int row, int image_width, int image_height) const;

private:
    Vector eye_;
    double screen_width_;
    double screen_height_;
    double screen_distance_;
};

} // namespace raytracer
