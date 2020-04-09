# CMake C boilerplate

A cross-platform C11 boilerplate project.

# Build and Run

On macOS/Linux/Unix:
```
mkdir build
cd build
cmake ..
make
```

or 

```
cmake -Bbuild
cd build
make
```

To run:
```
build/bin/main
```

or if you want the build commands saved to
build/compile_commands.json
```
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -Bbuild
```

There's a Visual Studio Code task to run main.
