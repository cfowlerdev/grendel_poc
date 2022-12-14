# Grendel POC

## Set up
```sh
# Enable emsdk
$ source "<EMSCRIPTEN_FOLDER>emsdk_env.sh"

# Build
$ mkdir build
$ cd build
$ emcmake cmake ..
$ make

# Run the app in a browser
$ emrun --browser chrome grendelpoc.html
```

## Todo
- Texture
- Mesh - has Shape, Program
- Shape
- Material
- Camera
- Renderer
