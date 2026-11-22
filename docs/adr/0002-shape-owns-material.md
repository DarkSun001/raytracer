# ADR 0002: A Shape owns a Material (composition, not inheritance)

## Status
Accepted

## Context
Every shape (currently `Sphere`, `Plane`) needs to carry how it looks
when lit — its colour, and later its reflectivity/texture. Two designs
were considered:

- **Inheritance**: `RedSphere`, `GreenPlane`, etc., or a `Sphere` base
  class subclassed per colour/material combination.
- **Composition**: `Shape` subclasses (`Sphere`, `Plane`) each hold a
  `Material` value; `Material` only describes appearance, `Shape` only
  describes geometry and intersection.

Inheritance here would multiply classes by every shape × material
combination, violating the client's own framing: "a sphere *has a*
material", not "a sphere *is a* material".

## Decision
`Material` is a small value type (currently just a `Colour`) stored as
a member on every concrete `Shape`. `Hit` carries a copy of the
material of whatever it hit, so `trace()` can shade it without knowing
the concrete shape type.

## Consequences
- Adding a new material property (e.g. reflectivity) touches one
  struct (`Material`), not every shape class.
- Adding a new shape (e.g. `Triangle`) only requires implementing
  `Shape::intersect`; it gets materials "for free" by holding a
  `Material` member like the others.
- `Shape::intersect` stays focused on geometry; shading logic
  (`lambert_intensity`, `trace`) lives separately in
  `include/raytracer/shading.h` and `render.h`, independently testable.
