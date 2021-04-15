include_directories(.)

add_executable(karasimulator_core_tests
        KaraCommandTest.cpp
        view/KaraViewModelTest.cpp
        util/GameStringifier.cpp util/GameStringifier.h
        util/TestUtils.cpp util/TestUtils.h
        util/DirectionTestHelper.cpp util/DirectionTestHelper.h
        view/KaraViewTestBase.cpp view/KaraViewTestBase.h
        view/KaraViewModelStringifier.cpp view/KaraViewModelStringifier.h view/UserInputInterfaceFake.cpp view/UserInputInterfaceFake.h
        )
target_link_libraries(karasimulator_core_tests karasimulator_core_lib gtest_main)
add_test(NAME karasimulator_core_tests COMMAND karasimulator_core_tests WORKING_DIRECTORY $<TARGET_FILE_DIR:karasimulator_core_tests>)

# Copy resources from binary root
add_custom_command(TARGET karasimulator_core_tests PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_BINARY_DIR}/resources/ $<TARGET_FILE_DIR:karasimulator_core_tests>/resources)
