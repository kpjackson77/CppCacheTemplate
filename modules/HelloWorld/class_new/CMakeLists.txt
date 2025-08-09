cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(class_new exercise/main.cpp)
add_executable(class_new_tests "${CMAKE_CURRENT_LIST_DIR}/tests/tests.cpp")
target_link_libraries(class_new_tests GTest::gtest_main)


add_dependencies(class_new_tests class_new)

gtest_add_tests(
    TARGET class_new_tests
)
