project(karasimulator_examples)

set(CMAKE_CXX_STANDARD 17)

# Executable Examples
add_executable(karasimulator_example01 Example01.cpp)
target_link_libraries(karasimulator_example01 karasimulator_main_lib)

add_executable(karasimulator_example02 Example02.cpp)
target_link_libraries(karasimulator_example02 karasimulator_main_lib)

add_executable(karasimulator_example03 Example03.cpp)
target_link_libraries(karasimulator_example03 karasimulator_main_lib)

# Copy resources from binary root (only trigger for one example)
add_custom_command(TARGET karasimulator_example01 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_BINARY_DIR}/resources/ ${CMAKE_CURRENT_BINARY_DIR}/resources)

if (MSVC)
    include(${CMAKE_SOURCE_DIR}/CMakeListsLocalProperties.cmake) # define SDL properties on Windows

    # copy SDL DLLs to output (karasimulator_example01)
    add_custom_command(TARGET karasimulator_example01 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SDL2_DIR}/lib/x64/ ${CMAKE_CURRENT_BINARY_DIR})
    # copy SDL_image DLLs to output
    add_custom_command(TARGET karasimulator_example01 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SDL2_IMAGE_DIR}/lib/x64/ ${CMAKE_CURRENT_BINARY_DIR})
    # copy SDL_ttf DLLs to output
    add_custom_command(TARGET karasimulator_example01 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SDL2_TTF_DIR}/lib/x64/ ${CMAKE_CURRENT_BINARY_DIR})

    # copy SDL DLLs to output (karasimulator_example02)
    add_custom_command(TARGET karasimulator_example02 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SDL2_DIR}/lib/x64/ ${CMAKE_CURRENT_BINARY_DIR})
    # copy SDL_image DLLs to output
    add_custom_command(TARGET karasimulator_example02 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SDL2_IMAGE_DIR}/lib/x64/ ${CMAKE_CURRENT_BINARY_DIR})
    # copy SDL_ttf DLLs to output
    add_custom_command(TARGET karasimulator_example02 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SDL2_TTF_DIR}/lib/x64/ ${CMAKE_CURRENT_BINARY_DIR})

    # copy SDL DLLs to output (karasimulator_example03)
    add_custom_command(TARGET karasimulator_example03 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SDL2_DIR}/lib/x64/ ${CMAKE_CURRENT_BINARY_DIR})
    # copy SDL_image DLLs to output
    add_custom_command(TARGET karasimulator_example03 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SDL2_IMAGE_DIR}/lib/x64/ ${CMAKE_CURRENT_BINARY_DIR})
    # copy SDL_ttf DLLs to output
    add_custom_command(TARGET karasimulator_example03 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SDL2_TTF_DIR}/lib/x64/ ${CMAKE_CURRENT_BINARY_DIR})

endif ()
