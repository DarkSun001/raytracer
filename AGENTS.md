# Working with AI on this project

An AI assistant may be used to draft code, tests, or documentation in this
repository, but every suggestion is treated as a starting point, not a
finished answer.

## Rules

- Do not accept generated code without reading it. If you can't explain
  what a function does, don't commit it.
- Every class gets tests before it is considered done. AI-generated tests
  still need to be checked against the spec (sphere/plane intersection
  math, Lambert shading) by hand.
- Architectural decisions (library choices, composition vs inheritance,
  interfaces) are recorded as ADRs in `docs/adr/`, written by a human,
  even if an AI proposed the option.
- Domain language stays the client's language (Vector, Ray, Sphere,
  Plane, Material, Camera, Scene, Image) — rename anything an AI
  introduces that drifts from it.
