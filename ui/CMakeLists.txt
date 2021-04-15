project(karasimulator_ui)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    include(${CMAKE_SOURCE_DIR}/CMakeListsLocalProperties.cmake) # define SDL properties on Windows
endif ()

# SDL
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/") ## use helper SDL2 cmake file (see https://github.com/trenki2/SDL2Test/tree/master/cmake)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include(IncludeNanogui.cmake)

# Own Sources
set(SRCS SdlApplicationListener.h
    SdlApplication.cpp SdlApplication.h
    KaraApplicationHandler.cpp KaraApplicationHandler.h
    SdlGameInputInterface.cpp SdlGameInputInterface.h
    util/InputDialogWindow.cpp util/InputDialogWindow.h
    util/GameLogControl.cpp util/GameLogControl.h
    util/SpeedSliderControl.cpp util/SpeedSliderControl.h
    util/WidgetBackgroundWrapper.cpp util/WidgetBackgroundWrapper.h
    util/LightTheme.h util/ControlWindowTheme.h
    util/ColorConverter.h)

# Library

add_library(karasimulator_ui_lib STATIC ${SRCS})
target_include_directories(karasimulator_ui_lib PUBLIC .)
target_link_libraries(karasimulator_ui_lib PUBLIC karasimulator_core_lib)
target_link_libraries(karasimulator_ui_lib PUBLIC nanogui_lib)

# Copy resources to binary root
add_custom_command(TARGET karasimulator_ui_lib PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/ ${CMAKE_BINARY_DIR}/resources)

if (MSVC)
    # copy SDL DLLs to output
    add_custom_command(TARGET karasimulator_ui_lib POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SDL2_DIR}/lib/x64/ $<TARGET_FILE_DIR:karasimulator_ui_lib>)
    # copy SDL_image DLLs to output
    add_custom_command(TARGET karasimulator_ui_lib POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SDL2_IMAGE_DIR}/lib/x64/ $<TARGET_FILE_DIR:karasimulator_ui_lib>)
    # copy SDL_ttf DLLs to output
    add_custom_command(TARGET karasimulator_ui_lib POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SDL2_TTF_DIR}/lib/x64/ $<TARGET_FILE_DIR:karasimulator_ui_lib>)
endif ()
