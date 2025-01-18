add_executable(runUnitTests tests.cpp)

target_link_libraries(runUnitTests gtest gtest_main)

add_test(runTests runUnitTests)