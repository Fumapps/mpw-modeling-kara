## Setup SDL

### MacOS

* `brew install sdl2`
* `brew install sdl2_image`
* `brew install sdl2_ttf`

### Windows

* download development libraries, extract them to a directory
    * SDL2: https://libsdl.org/release/SDL2-devel-2.0.14-VC.zip
    * SDL2 Image: https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-VC.zip
    * SDL2 TTF: https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.15-VC.zip
* extend `CMakeListsLocalProperties.cmake` file
    * set a `SDL2_DIR` variable: `set(SDL2_DIR "<path-to-sdl-dir>")`
    * set a `SDL2_IMAGE_DIR` variable: `set(SDL2_IMAGE_DIR "<path-to-sdl-image-dir>")`
    * set a `SDL2_TTF_DIR` variable: `set(SDL2_TTF_DIR "<path-to-sdl-ttf-dir>")`
* Note: `CMakeListsLocalProperties.cmake` has to be placed on simulator root directory (besides top-level CMakeLists.txt / CMAKE_CURRENT_SOURCE_DIR)

### SDL notes

* setup based on: https://trenki2.github.io/blog/2017/07/04/using-sdl2-image-with-cmake/

## IDE

### CMake arguments

* suppress FindSDL2 warning: `-Wno-dev`