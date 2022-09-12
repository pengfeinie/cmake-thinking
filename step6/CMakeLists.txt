cmake_minimum_required(VERSION 3.16.3)

# set the project name and version
# https://cmake.org/cmake/help/latest/command/project.html
project(tutorial6_main)

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
add_executable(${PROJECT_NAME}  ${CMAKE_CURRENT_SOURCE_DIR}/src/tutorial6.cpp)


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


# add the install targets
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  DESTINATION include
  )

# enable testing
enable_testing()

# does the application run
add_test(NAME Runs COMMAND ${PROJECT_NAME} 25)

# does the usage message work?
add_test(NAME Usage COMMAND ${PROJECT_NAME})
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
  )

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

# do a bunch of result based tests
do_test(${PROJECT_NAME} 4 "4 is 2")
do_test(${PROJECT_NAME} 9 "9 is 3")
do_test(${PROJECT_NAME} 5 "5 is 2.236")
do_test(${PROJECT_NAME} 7 "7 is 2.645")
do_test(${PROJECT_NAME} 25 "25 is 5")
do_test(${PROJECT_NAME} -25 "-25 is (-nan|nan|0)")
do_test(${PROJECT_NAME} 0.0001 "0.0001 is 0.01")