# ADR 0001: Use lodepng for PNG output

## Status
Accepted

## Context
The raytracer needs to save a rendered image as a PNG file. Candidates
considered:

- **lodepng**: single `.cpp`/`.h` pair, no system dependencies, MIT-style
  (zlib) license.
- **libpng**: the reference implementation, but depends on system zlib
  and a dev package, which has to be installed and version-matched in
  every environment (local machine, CI, teammates' containers).
- **stb_image_write**: also header-only, but its PNG encoder is
  unconditionally uncompressed/naive compared to lodepng, and lacks the
  decode half we may want later for comparing reference renders.

## Decision
Use lodepng, pulled via CMake `FetchContent` and compiled as a small
static library target (`lodepng`) that `raytracer_lib` links against.

## Consequences
- No system package to install beyond a C++ compiler — the dev
  container only needs `build-essential`, `cmake`, and `git`.
- Image writing is isolated behind our own `ImageWriter` interface
  (Strategy pattern, see `include/raytracer/image_writer.h`), so
  swapping lodepng for another encoder later only touches
  `PngImageWriter`, not `Scene`/`render`/`main`.
- `FetchContent` pins the `GIT_TAG` to `master` for now; before m2 we
  should pin to a specific commit hash for reproducible builds.
