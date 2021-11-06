cmake_minimum_required(VERSION 3.21)

project(EquationLibrary)

set(SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/write.cpp
)

#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/physic.json ${CMAKE_CURRENT_BINARY_DIR}/physic.json COPYONLY)

add_executable(EquationLibrary ${CMAKE_CURRENT_SOURCE_DIR}/Test.cpp ${SRCS})

target_compile_options(EquationLibrary PUBLIC -O3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)