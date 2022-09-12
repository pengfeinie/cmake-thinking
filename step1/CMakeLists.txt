cmake_minimum_required(VERSION 3.16.3)

# set the project name and version
# https://cmake.org/cmake/help/latest/command/project.html
project(tutorial1_main)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
# https://cmake.org/cmake/help/latest/command/add_executable.html
# https://cmake.org/cmake/help/latest/variable/CMAKE_CURRENT_SOURCE_DIR.html
# https://cmake.org/cmake/help/latest/variable/PROJECT_NAME.html
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/tutorial1.cpp)