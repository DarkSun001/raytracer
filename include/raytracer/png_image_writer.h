#pragma once

#include "raytracer/image_writer.h"

namespace raytracer {

// Adapter around the lodepng library: translates our domain Image
// into the byte buffer lodepng's API expects. See docs/adr/0001.
class PngImageWriter : public ImageWriter {
public:
    bool save(const Image& image, const std::string& filename) const override;
};

} // namespace raytracer
