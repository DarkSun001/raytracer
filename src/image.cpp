#include "raytracer/image.h"

#include <stdexcept>

namespace raytracer {

Image::Image(int width, int height)
    : width_(width), height_(height), pixels_(static_cast<size_t>(width) * height) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Image dimensions must be positive");
    }
}

void Image::set(int x, int y, const Colour& colour) {
    pixels_[static_cast<size_t>(y) * width_ + x] = colour;
}

const Colour& Image::get(int x, int y) const {
    return pixels_[static_cast<size_t>(y) * width_ + x];
}

} // namespace raytracer
