project(karasimulator_main)

set(CMAKE_CXX_STANDARD 17)

# Own Sources
set(SRCS
    SimpleKaraGame.cpp SimpleKaraGame.h)

# Library

get_target_property(karasimulator_core_lib_FACADE_INCLUDES karasimulator_core_lib FACADE_INCLUDES)
get_target_property(mpw_framework_core_lib_FACADE_INCLUDES mpw_framework_core_lib FACADE_INCLUDES)

add_library(karasimulator_main_lib STATIC ${SRCS})
target_include_directories(karasimulator_main_lib PUBLIC .)
target_include_directories(karasimulator_main_lib PUBLIC ${karasimulator_core_lib_FACADE_INCLUDES})
target_include_directories(karasimulator_main_lib PUBLIC ${mpw_framework_core_lib_FACADE_INCLUDES})
target_link_libraries(karasimulator_main_lib PRIVATE karasimulator_core_lib PRIVATE karasimulator_ui_lib)
