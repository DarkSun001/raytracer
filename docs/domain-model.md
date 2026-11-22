# Domain model

Reverse ray tracing: instead of following photons from a light source,
we shoot one ray per pixel from the camera's eye and ask what it hits.

## Entities

- **Vector** `(x, y, z)` — the only math primitive. Supports addition,
  subtraction, scalar multiplication, dot product, length,
  normalization. Points, directions, normals, and colours in this
  codebase are *not* all `Vector` — only geometric quantities are;
  `Colour` is its own type (see below) to keep "a point in space" and
  "a colour" from being accidentally interchangeable.
- **Ray** — `origin` + `direction`, both `Vector`. `point_at(t)` gives
  any point along it: `P(t) = origin + t * direction`.
- **Colour** — `(r, g, b)` in `[0, 1]`, independent of `Vector` even
  though the arithmetic looks similar, because colours clamp and
  convert to bytes; vectors don't.
- **Material** — currently just a `Colour`. A `Shape` *has* a
  `Material` (composition, see ADR 0002), it does not subclass one.
- **Shape** (interface) — anything with `intersect(Ray) -> optional<Hit>`.
  - **Sphere** — `center`, `radius`, `material`. Intersection solves
    the quadratic `|O + tD - C|^2 = r^2`.
  - **Plane** — `point`, `normal`, `material`. Intersection solves
    `t = (point - O)·n / (D·n)`, rejecting rays parallel to the plane.
- **Hit** — the result of a successful intersection: `t` (distance
  along the ray), `point`, surface `normal`, and the `material` of
  whatever was hit.
- **Camera** — a pinhole: an `eye` position and a screen plane
  `screen_distance` in front of it, spanning `screen_width` ×
  `screen_height` world units. `ray_for_pixel(col, row, image_width,
  image_height)` maps a pixel to the ray through its center.
- **Scene** — owns every `Shape`, plus a light direction and a
  background `Colour`. `closest_hit(Ray)` returns the nearest
  intersection across all shapes, or nothing.
- **Image** — a `width` × `height` grid of `Colour`.
- **ImageWriter** (interface, Strategy pattern) — `save(Image, path)`.
  **PngImageWriter** is the only implementation so far (adapts
  lodepng, see ADR 0001).

## Pipeline

```
Camera.ray_for_pixel(pixel) -> Ray
           |
           v
Scene.closest_hit(Ray) -> optional<Hit>
           |
           v
trace(Ray, Scene) -> Colour            (Lambert shading, or background)
           |
           v
render(Scene, Camera, w, h) -> Image
           |
           v
PngImageWriter.save(Image, "output.png")
```

## Shading

Lambert's law: a surface's brightness is proportional to
`max(0, N · L)`, where `N` is the surface normal and `L` is the unit
vector pointing toward the light. Implemented standalone in
`shading.h` (`lambert_intensity`) so it is testable without a full
`Scene`/`Camera` setup.
