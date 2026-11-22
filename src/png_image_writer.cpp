#include "raytracer/png_image_writer.h"

#include <vector>

#include "lodepng.h"

namespace raytracer {

bool PngImageWriter::save(const Image& image, const std::string& filename) const {
    std::vector<unsigned char> pixels;
    pixels.reserve(static_cast<size_t>(image.width()) * image.height() * 4);

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            const RgbByte rgb = image.get(x, y).to_bytes();
            pixels.push_back(rgb.r);
            pixels.push_back(rgb.g);
            pixels.push_back(rgb.b);
            pixels.push_back(255);
        }
    }

    const unsigned error = lodepng::encode(
        filename, pixels, static_cast<unsigned>(image.width()), static_cast<unsigned>(image.height()));
    return error == 0;
}

} // namespace raytracer
