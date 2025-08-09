cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(first_templates exercise/main.cpp)
add_executable(first_templates_tests "${CMAKE_CURRENT_LIST_DIR}/tests/tests.cpp")
target_link_libraries(first_templates_tests GTest::gtest_main)


add_dependencies(first_templates_tests first_templates)

gtest_add_tests(
    TARGET first_templates_tests
)
