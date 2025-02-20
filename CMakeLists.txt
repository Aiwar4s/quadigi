cmake_minimum_required(VERSION 3.14)
project(quadigi VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(quadigi
    main.cpp
    classes/ExpressionParser.cpp
    classes/Sum.cpp
    classes/Subtract.cpp
    classes/Multiply.cpp
    classes/Divide.cpp
    classes/Value.cpp
    classes/VariableFill.cpp
)

target_include_directories(quadigi PRIVATE classes interfaces)

enable_testing()

add_executable(
  TestSum
  tests/TestSum.cpp
  classes/Sum.cpp
  classes/Value.cpp
)
target_link_libraries(
  TestSum
  GTest::gtest_main
)
target_include_directories(TestSum PRIVATE classes interfaces tests)

include(GoogleTest)
gtest_discover_tests(TestSum)

add_executable(
  TestMultiply
  tests/TestMultiply.cpp
  classes/Multiply.cpp
  classes/Value.cpp
)
target_include_directories(TestMultiply PRIVATE classes interfaces)
target_link_libraries(TestMultiply GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(TestMultiply)

add_executable(
  TestParsing
  tests/TestParsing.cpp
  classes/ExpressionParser.cpp
  classes/Value.cpp
  classes/Sum.cpp
  classes/Subtract.cpp
  classes/Multiply.cpp
  classes/Divide.cpp
  classes/VariableFill.cpp
)
target_include_directories(TestParsing PRIVATE classes interfaces)
target_link_libraries(TestParsing GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(TestParsing)