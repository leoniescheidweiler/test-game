all:
	mkdir -p bin
	cmake -B build
	cmake --build build --config Release

clean:
	rm -rf build bin
