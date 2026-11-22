#pragma once

#include <string>

#include "raytracer/image.h"

namespace raytracer {

// Strategy interface: decouples the rendering pipeline from any one
// file format. Swapping PNG for another format means adding a new
// implementation, not touching callers (open/closed principle).
class ImageWriter {
public:
    virtual ~ImageWriter() = default;
    virtual bool save(const Image& image, const std::string& filename) const = 0;
};

} // namespace raytracer
