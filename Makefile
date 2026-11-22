.PHONY: configure build test run clean

configure:
	cmake --preset default

build: configure
	cmake --build --preset default

test: build
	ctest --preset default

run: build
	./build/raytracer

clean:
	rm -rf build
