# ADR 0003: Dev container + CMake FetchContent for dependencies

## Status
Accepted

## Context
Without a shared environment, new contributors spend time installing
compilers/CMake versions, and "works on my machine" bugs appear when
test results differ across platforms. We also need Catch2 (tests) and
lodepng (PNG output, see ADR 0001) without manually vendoring source.

## Decision
- Provide a `Dockerfile` (Ubuntu 22.04 + build-essential + cmake + git)
  and a matching `.devcontainer/devcontainer.json`, so "clone, open in
  container, `make build`" is the whole onboarding story.
- Fetch Catch2 and lodepng via CMake `FetchContent` instead of
  committing their sources or requiring a system package manager step.
- Expose `CMakePresets.json` so `cmake --preset default` is identical
  on every machine, and a thin `Makefile` wrapping the preset commands
  for muscle-memory `make build` / `make test` / `make run`.

## Consequences
- The container gives everyone the same Linux + compiler + CMake
  version, but not the same CPU architecture — Apple Silicon (ARM) and
  x86-64 hosts both run Linux inside Docker, but native binaries still
  differ, and pixel-for-pixel image comparisons across machines must
  tolerate that.
- This does not test native Windows/macOS builds; cross-platform bugs
  outside the container remain possible and are out of scope for m1.
- Building requires network access the first time (FetchContent clones
  Catch2/lodepng); offline rebuilds work once the CMake cache/
  `_deps` directory is populated.
