cmake_minimum_required(VERSION 3.26)
project(dm_fall_2023)

set(CMAKE_CXX_STANDARD 20)

# add_library(dm_fall_2023 SHARED Natural/NATURAL.cpp
#         main.cpp)
add_executable(dm_fall_2023 main.cpp Natural/NATURAL.cpp
        Natural/COM_NN_D.cpp
        Natural/NZER_N_B.cpp
        Natural/ADD_NN_N.cpp
        Natural/SUB_NN_N.cpp
        Natural/MUL_ND_N.cpp
        Natural/MUL_Nk_N.cpp
        Natural/MUL_NN_N.cpp
        Natural/SUB_NDN_N.cpp
        Natural/DIV_NN_Dk.cpp
        Natural/DIV_NN_N.cpp
        Natural/MOD_NN_N.cpp
        Natural/GCF_NN_N.cpp
        Natural/LCM_NN_N.cpp
        Integer/INTEGER.cpp
        Polinom/POLINOM.cpp
        Polinom/LED_P_Q.cpp
)
