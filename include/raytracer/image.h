#pragma once

#include <vector>

#include "raytracer/colour.h"

namespace raytracer {

class Image {
public:
    Image(int width, int height);

    int width() const { return width_; }
    int height() const { return height_; }

    void set(int x, int y, const Colour& colour);
    const Colour& get(int x, int y) const;

private:
    int width_;
    int height_;
    std::vector<Colour> pixels_;
};

} // namespace raytracer
