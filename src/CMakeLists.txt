cmake_minimum_required(VERSION 3.26)
project(dm_fall_2023)

set(CMAKE_CXX_STANDARD 20)

# add_library(dm_fall_2023 SHARED Natural/NATURAL.cpp
#         main.cpp)
add_executable(dm_fall_2023 main.cpp Natural/NATURAL.cpp
        Natural/NZER_N_B.cpp
        Natural/MUL_ND_N.cpp
        Integer/INTEGER.cpp
        Natural/ADD_NN_N.cpp
)
