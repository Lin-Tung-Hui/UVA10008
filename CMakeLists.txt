#-------------------------------------------------------------------------------
# CMake Setups
#-------------------------------------------------------------------------------
CMAKE_MINIMUM_REQUIRED (VERSION 3.15)

#-------------------------------------------------------------------------------
# Project Setups
#-------------------------------------------------------------------------------
PROJECT (Cryptanalysis)
ENABLE_LANGUAGE(C CXX)

option(GTEST "Enable Google Test" ON)

SET(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_COLOR_MAKEFILE ON)
SET(CMAKE_ERROR_DEPRECATED ON)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_CXX_FLAGS "-std=c++11 -O2")

# Set version
set(VERSION_MAJOR "0")
set(VERSION_MINOR "0")
set(VERSION_PATCH "1")
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

#-------------------------------------------------------------------------------
# CMake Modules
#-------------------------------------------------------------------------------
INCLUDE(GNUInstallDirs)
INCLUDE(FeatureSummary)
INCLUDE(FindPkgConfig)

if(GTEST)
  find_package(GTest CONFIG REQUIRED)
  ADD_DEFINITIONS("-DGTEST")
endif()

if(GTEST)
add_executable(test_runner unittest.cpp)
target_link_libraries(test_runner GTest::gtest)

add_custom_command(
  TARGET test_runner POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
          ${CMAKE_CURRENT_SOURCE_DIR}/data/*
          ${CMAKE_CURRENT_BINARY_DIR}/)

else()
add_executable(main main.cpp)
endif()

