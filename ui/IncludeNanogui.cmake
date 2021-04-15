# SDL2 Nanogui toolkit
## Note: since the cmake at the GitHub repo for nanogui is not well-defined enough,
## here a custom target "nanogui_lib" is created.

# Fetch nanogui sources
SET(NANOGUI_BUILD_EXAMPLE OFF CACHE BOOL "disable nanogui example")
include(FetchContent)
FetchContent_Declare(
        nanogui
        GIT_REPOSITORY https://github.com/SQAHamster/mpw-nanogui-sdl
        CMAKE_ARGS "-Wno-dev"
)
FetchContent_GetProperties(nanogui)
FetchContent_MakeAvailable(nanogui)

# Retrieve the list of source files from the subdir cmake configuration and store it as NANOGUI_SRCS
## Note: add the "sdlgui" include prefix
get_directory_property(NANOGUI_SRCS DIRECTORY ${nanogui_SOURCE_DIR} DEFINITION NNGUI_BASIC_SOURCE)
string(REGEX REPLACE "(sdlgui/[a-z_]+\\.(h|cpp|c))" "${nanogui_SOURCE_DIR}/\\1" NANOGUI_SRCS "${NANOGUI_SRCS}")

# Fix removed usage of std::unary_function in nanogui src (function is removed by C++ 17)
file(READ "${nanogui_SOURCE_DIR}/sdlgui/nanort.h" nanort_header_file_content)
string(REGEX REPLACE "std::unary_function\\<unsigned int, bool\\>" "std::function<bool(unsigned int)>" nanort_header_file_content "${nanort_header_file_content}")
file(WRITE "${nanogui_SOURCE_DIR}/sdlgui/nanort.h" "${nanort_header_file_content}")

# Add the "nanogui_lib" target
add_library(nanogui_lib STATIC ${NANOGUI_SRCS})
target_include_directories(nanogui_lib SYSTEM PUBLIC ${nanogui_SOURCE_DIR})
target_include_directories(nanogui_lib SYSTEM PRIVATE ${nanogui_SOURCE_DIR}/sdlgui) # for nanogui files, allow "direct" includes in same folder
target_include_directories(nanogui_lib PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR})
target_include_directories(nanogui_lib PUBLIC ${SDL2_INCLUDE_DIRS}/.. ${SDL2IMAGE_INCLUDE_DIR}/.. ${SDL2TTF_INCLUDE_DIR}/..) # for nanogui internal includes
target_link_libraries(nanogui_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})

# Disable Nanogui warnings
if (CMAKE_COMPILER_IS_GNUCC)
    set_source_files_properties(${NANOGUI_SRCS}
            PROPERTIES
            COMPILE_FLAGS "-Wno-all -Wno-extra -Wno-format-truncation -Wno-narrowing")
endif ()
if (CMAKE_CXX_COMPILER_ID STREQUAL Clang OR
        CMAKE_CXX_COMPILER_ID STREQUAL AppleClang)
    set_source_files_properties(${NANOGUI_SRCS}
            PROPERTIES
            COMPILE_FLAGS "-Wno-c++11-narrowing -Wno-inconsistent-missing-override")
endif ()
if (MSVC)
    set_source_files_properties(${NANOGUI_SRCS}
            PROPERTIES
            COMPILE_FLAGS "/w")
endif ()

set_target_properties(nanogui_lib PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(nanogui_lib PROPERTIES CMAKE_CXX_STANDARD 11)
