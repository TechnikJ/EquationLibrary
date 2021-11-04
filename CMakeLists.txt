cmake_minimum_required(VERSION 3.21)

project(EquationLibrary)

set(SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/write.cpp
)

add_executable(EquationLibrary ${CMAKE_CURRENT_SOURCE_DIR}/Test.cpp ${SRCS})

target_compile_options(MultiGridMethod PUBLIC -O3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)