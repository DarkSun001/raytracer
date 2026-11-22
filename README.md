# Raytracer

A pinhole raytracer in C++17, built for the Glassworks raytracer module.
Renders a sphere on a ground plane, shaded with Lambert's law, to a PNG.

## Requirements

- A Linux dev environment (use the provided Docker image / devcontainer —
  see `Dockerfile` and `.devcontainer/`) with `build-essential`, `cmake`,
  and `git`.

## Build, test, run

```sh
make build   # configure + compile
make test    # run the Catch2 unit test suite
make run     # render output.png in the project root
```

Equivalent without `make`:

```sh
cmake --preset default
cmake --build --preset default
ctest --preset default
./build/raytracer
```

## Project layout

```
include/raytracer/   public headers, one class/concept per file
src/                 implementations + main.cpp
tests/                Catch2 unit tests
docs/adr/            Architecture Decision Records
docs/domain-model.md domain entities and relationships
```

## Domain model

Vector -> Ray -> Shape (Sphere, Plane) -> Hit -> Material -> Scene -> Image -> PNG.
See `docs/domain-model.md` for details.
