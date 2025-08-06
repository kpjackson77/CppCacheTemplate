cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(step4_cache exercise/main.cpp)
add_executable(step4_cache_tests "${CMAKE_CURRENT_LIST_DIR}/tests/tests.cpp")
target_link_libraries(step4_cache_tests GTest::gtest_main)


add_dependencies(step4_cache_tests step4_cache)

gtest_add_tests(
    TARGET step4_cache_tests
)
