cmake_minimum_required(VERSION 3.16.3)

# set the project name and version
# https://cmake.org/cmake/help/latest/command/project.html
project(tutorial5_main)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)


# configure a header file to pass some of the CMake settings to the source code
# https://cmake.org/cmake/help/latest/variable/CMAKE_CURRENT_SOURCE_DIR.html
# https://cmake.org/cmake/help/latest/command/configure_file.html
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/TutorialConfig.h.in TutorialConfig.h)


# https://cmake.org/cmake/help/latest/command/add_subdirectory.html
add_subdirectory(my_hello)
list(APPEND EXTRA_MY_HELLO_LIBS myself_hello)
list(APPEND EXTRA_MY_HELLO_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/my_hello/include)

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)
if(USE_MYMATH)
    add_compile_options(-DUSE_MYMATH)
    add_subdirectory(my_math)
    list(APPEND EXTRA_MY_MATH_LIBS myself_math)
    list(APPEND EXTRA_MY_MATH_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/my_math/include)
endif()

# add the executable
# https://cmake.org/cmake/help/latest/command/add_executable.html
# https://cmake.org/cmake/help/latest/variable/CMAKE_CURRENT_SOURCE_DIR.html
# https://cmake.org/cmake/help/latest/variable/PROJECT_NAME.html
add_executable(${PROJECT_NAME}  ${CMAKE_CURRENT_SOURCE_DIR}/src/tutorial5.cpp)


# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# https://cmake.org/cmake/help/latest/variable/PROJECT_BINARY_DIR.html
# https://cmake.org/cmake/help/latest/command/target_include_directories.html
target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                           ${EXTRA_MY_HELLO_INCLUDES}
                           ${EXTRA_MY_MATH_INCLUDES}
                           )

target_link_libraries(${PROJECT_NAME} PUBLIC 
                            ${EXTRA_MY_HELLO_LIBS}
                            ${EXTRA_MY_MATH_LIBS})