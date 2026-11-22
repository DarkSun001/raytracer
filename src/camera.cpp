#include "raytracer/camera.h"

namespace raytracer {

Camera::Camera(const Vector& eye, double screen_width, double screen_height, double screen_distance)
    : eye_(eye),
      screen_width_(screen_width),
      screen_height_(screen_height),
      screen_distance_(screen_distance) {}

Ray Camera::ray_for_pixel(int col, int row, int image_width, int image_height) const {
    const double u = (col + 0.5) / static_cast<double>(image_width);
    const double v = (row + 0.5) / static_cast<double>(image_height);

    const double screen_x = (u - 0.5) * screen_width_;
    const double screen_y = (0.5 - v) * screen_height_; // flip so row 0 is top of image

    const Vector screen_point(eye_.x() + screen_x, eye_.y() + screen_y, eye_.z() - screen_distance_);
    const Vector direction = (screen_point - eye_).normalized();
    return Ray(eye_, direction);
}

} // namespace raytracer
