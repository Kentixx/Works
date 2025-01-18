project(tests)

add_subdirectory(lib)
include_directories(lib/include/gtest)
add_executable(Google_Tests_run tests.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
