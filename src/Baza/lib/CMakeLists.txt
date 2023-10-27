cmake_minimum_required(VERSION 3.25)
project(Lib)
add_library(
    num_lib
    u_num.cpp num.cpp rational_fraction.cpp polinom.cpp
    u_num.h num.h rational_fraction.h polinom.h
)
target_include_directories(
    num_lib PUBLIC
    {CMAKE_CURRENT_SOURCE_DIR}
)
