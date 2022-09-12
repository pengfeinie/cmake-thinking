
# set the project name and version
# https://cmake.org/cmake/help/latest/command/project.html
project(myself_math)

#https://cmake.org/cmake/help/latest/command/add_library.html
add_library(${PROJECT_NAME} STATIC 
                            ${CMAKE_CURRENT_SOURCE_DIR}/src/basic_math_function.cpp
                            ${CMAKE_CURRENT_SOURCE_DIR}/src/complex_math_function.cpp)


# add the binary tree to the search path for include files
# https://cmake.org/cmake/help/latest/variable/PROJECT_BINARY_DIR.html
# https://cmake.org/cmake/help/latest/command/target_include_directories.html
target_include_directories(${PROJECT_NAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
                           )