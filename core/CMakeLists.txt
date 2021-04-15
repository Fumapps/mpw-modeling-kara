project(karasimulator_core)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_POSITION_INDEPENDENT_CODE ON) # -fPIC on gcc

## Setup MPW Simulator Framework

include(FetchContent)

FetchContent_Declare(mpw_lib
        GIT_REPOSITORY https://github.com/SQAHamster/mpw-modeling-framework.git
        GIT_TAG 1.0.1-cpp-framework
        SOURCE_DIR mpw_lib
        CMAKE_ARGS "-Wno-dev"
)
FetchContent_GetProperties(mpw_lib)
FetchContent_MakeAvailable(mpw_lib)

## Karasimulator

add_subdirectory(src/commands/generated)
add_subdirectory(src/generated)
add_subdirectory(src/impl)
set(SRCS ${GEN_SRCS} ${IMPL_SRCS} ${FRAMEWORK_SRCS})

add_library(karasimulator_core_lib STATIC ${SRCS})
target_link_libraries(karasimulator_core_lib mpw_framework_core_lib)

# Define facade include directories
set(FACADE_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src/facade ${CMAKE_CURRENT_SOURCE_DIR}/src/facade/generated)
set_property(TARGET karasimulator_core_lib PROPERTY FACADE_INCLUDES ${FACADE_INCLUDES}) # attach to target to make the property retrievable for other projects

target_include_directories(karasimulator_core_lib PUBLIC src/commands/generated)
target_include_directories(karasimulator_core_lib PUBLIC ${FACADE_INCLUDES})
target_include_directories(karasimulator_core_lib PUBLIC src/kara/generated)
target_include_directories(karasimulator_core_lib PUBLIC src/impl)

# Copy resources to binary root
add_custom_command(TARGET karasimulator_core_lib PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/ ${CMAKE_BINARY_DIR}/resources)

## Setup GTEST

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.10.0
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(test)
