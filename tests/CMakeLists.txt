cmake_minimum_required(VERSION 3.10)

add_executable(pbrtTest core/GeometryTest.cpp)

target_link_libraries(pbrtTest PUBLIC
        gtest_main
        pbrt
        )

target_include_directories(pbrtTest PUBLIC ../src)

add_test(
        NAME pbrtTest
        COMMAND pbrtTest
)