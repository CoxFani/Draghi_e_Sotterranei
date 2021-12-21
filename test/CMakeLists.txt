cmake_minimum_required(VERSION 3.16)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp HeroTest.cpp HeroFixture.cpp)
add_executable(runHeroTests ${TEST_SOURCE_FILES})
target_link_libraries(runHeroTests gtest gtest_main core)