cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(step3_cache exercise/main.cpp)
add_executable(step3_cache_tests "${CMAKE_CURRENT_LIST_DIR}/tests/tests.cpp")
target_link_libraries(step3_cache_tests GTest::gtest_main)


add_dependencies(step3_cache_tests step3_cache)

gtest_add_tests(
    TARGET step3_cache_tests
)
