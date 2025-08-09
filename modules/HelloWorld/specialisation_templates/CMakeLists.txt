cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(specialisation_templates exercise/main.cpp)
add_executable(specialisation_templates_tests "${CMAKE_CURRENT_LIST_DIR}/tests/tests.cpp")
target_link_libraries(specialisation_templates_tests GTest::gtest_main)


add_dependencies(specialisation_templates_tests specialisation_templates)

gtest_add_tests(
    TARGET specialisation_templates_tests
)
