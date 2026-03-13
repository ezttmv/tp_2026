# cmake_minimum_required(VERSION 3.5)
# project(labT4 LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

# add_library(labT4_lib INTERFACE)
# target_include_directories(labT4_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# #GoogleTests
# include(FetchContent)
# FetchContent_Declare(
#     googletest
#     URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
# )
# FetchContent_MakeAvailable(googletest)

# add_executable(tests tests/test.cpp)

# if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
#     target_compile_options(tests PRIVATE -fsanitize=address -fno-omit-frame-pointer -g)
#     target_link_options(tests PRIVATE -fsanitize=address)
# endif()

# target_link_libraries(tests PRIVATE gtest_main linked_order_lib)

# enable_testing()
# add_test(NAME unit_tests COMMAND tests)





cmake_minimum_required(VERSION 3.11)
project(shapes_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Включаем исходники библиотеки фигур
include_directories(${CMAKE_SOURCE_DIR}/include)

# Собираем библиотеку shapes (пример: перечислите свои .cpp)
add_library(shapes STATIC
    src/rectangle.cpp
    src/ellipse.cpp
    src/compositeShape.cpp
    src/demo_shapes.cpp
    src/shapeContainer.cpp
    src/shapePrinter.cpp
)

# Подключаем GoogleTest через FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Тестовый исполняемый файл
add_executable(unit_tests
    tests/test_rectangle.cpp
    tests/test_ellipse.cpp
    tests/test_composite.cpp
    tests/test_main.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
     target_compile_options(unit_tests PRIVATE -fsanitize=address -fno-omit-frame-pointer -g)
     target_link_options(unit_tests PRIVATE -fsanitize=address)
endif()

target_link_libraries(unit_tests PRIVATE shapes gtest_main)

# Опции компилятора
if (MSVC)
  target_compile_options(shapes PRIVATE /W4)
  target_compile_options(unit_tests PRIVATE /W4)
else()
  target_compile_options(shapes PRIVATE -Wall -Wextra -Wpedantic)
  target_compile_options(unit_tests PRIVATE -Wall -Wextra -Wpedantic)
endif()

include(GoogleTest)
gtest_discover_tests(unit_tests)


