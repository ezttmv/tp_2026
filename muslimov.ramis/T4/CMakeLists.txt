cmake_minimum_required(VERSION 3.10)
project(labT4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(labT4_lib INTERFACE)
target_include_directories(labT4_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

#GoogleTests
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(tests tests/test.cpp)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(tests PRIVATE -fsanitize=address -fno-omit-frame-pointer -g)
    target_link_options(tests PRIVATE -fsanitize=address)
endif()

target_link_libraries(tests PRIVATE gtest_main linked_order_lib)

enable_testing()
add_test(NAME unit_tests COMMAND tests)
