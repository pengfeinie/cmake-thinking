cmake_minimum_required(VERSION 3.16.3)

# set the project name and version
# https://cmake.org/cmake/help/latest/command/project.html
project(tutorial2_main)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)


# configure a header file to pass some of the CMake settings to the source code
# https://cmake.org/cmake/help/latest/variable/CMAKE_CURRENT_SOURCE_DIR.html
# https://cmake.org/cmake/help/latest/command/configure_file.html
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/TutorialConfig.h.in TutorialConfig.h)

# add the executable
# https://cmake.org/cmake/help/latest/command/add_executable.html
# https://cmake.org/cmake/help/latest/variable/CMAKE_CURRENT_SOURCE_DIR.html
add_executable(tutorial2_main ${CMAKE_CURRENT_SOURCE_DIR}/src/tutorial2.cpp)


# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# https://cmake.org/cmake/help/latest/variable/PROJECT_BINARY_DIR.html
# https://cmake.org/cmake/help/latest/command/target_include_directories.html
target_include_directories(tutorial2_main PUBLIC
                           ${PROJECT_BINARY_DIR}
                           )