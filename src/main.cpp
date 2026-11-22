#include <iostream>

#include "raytracer/camera.h"
#include "raytracer/colour.h"
#include "raytracer/material.h"
#include "raytracer/plane.h"
#include "raytracer/png_image_writer.h"
#include "raytracer/render.h"
#include "raytracer/scene.h"
#include "raytracer/sphere.h"

int main() {
    using namespace raytracer;

    Material red_material{Colour(0.8, 0.15, 0.15)};
    Material ground_material{Colour(0.3, 0.55, 0.3)};

    Scene scene;
    scene.add(std::make_unique<Sphere>(Vector(0.0, 0.0, -5.0), 1.0, red_material));
    scene.add(std::make_unique<Plane>(Vector(0.0, -1.0, 0.0), Vector(0.0, 1.0, 0.0), ground_material));
    scene.set_light_direction(Vector(-1.0, 1.0, 1.0));

    const Camera camera(Vector(0.0, 0.0, 0.0), 4.0, 3.0, 2.0);

    const int width = 1280;
    const int height = 960;
    const Image image = render(scene, camera, width, height);

    const PngImageWriter writer;
    const std::string output_path = "output.png";
    if (!writer.save(image, output_path)) {
        std::cerr << "Failed to write " << output_path << "\n";
        return 1;
    }

    std::cout << "Rendered " << width << "x" << height << " image to " << output_path << "\n";
    return 0;
}
