cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(final_cache exercise/main.cpp)
add_executable(final_cache_tests "${CMAKE_CURRENT_LIST_DIR}/tests/tests.cpp")
target_link_libraries(final_cache_tests GTest::gtest_main)


add_dependencies(final_cache_tests final_cache)

gtest_add_tests(
    TARGET final_cache_tests
)
