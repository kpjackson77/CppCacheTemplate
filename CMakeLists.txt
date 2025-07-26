cmake_minimum_required(VERSION 3.10)
project(hello_project VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
# Fetching GoogleTest and GoogleMock
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/6910c9d9165801d8827d628cb72eb7ea9dd538c5.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()

add_library(utilities modules/lib/utilities.cpp)
target_include_directories(utilities PUBLIC include)

add_subdirectory(modules/HelloWorld/step1_helloworld)
