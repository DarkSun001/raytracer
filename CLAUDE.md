# Project context for Claude

C++17 raytracer built for the Glassworks raytracer module. See
`docs/domain-model.md` for the entity model and `docs/adr/` for
recorded decisions before proposing a different design.

- Build/test: `make build`, `make test` (wraps CMake presets).
- Style: header in `include/raytracer/`, implementation in `src/`,
  one class per file, TDD where the behaviour is spec'd by math
  (Vector, Sphere, Plane), spike-first where the design is still
  unclear.
- Do not introduce a new third-party dependency without an ADR.
