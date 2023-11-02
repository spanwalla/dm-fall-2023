cmake_minimum_required(VERSION 3.26)
project(dm_fall_2023 VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

add_library(cls SHARED src/Natural/NATURAL.cpp
        src/Natural/COM_NN_D.cpp
        src/Natural/NZER_N_B.cpp
        src/Natural/ADD_1N_N.cpp
        src/Natural/ADD_NN_N.cpp
        src/Natural/SUB_NN_N.cpp
        src/Natural/MUL_ND_N.cpp
        src/Natural/MUL_Nk_N.cpp
        src/Natural/MUL_NN_N.cpp
        src/Natural/SUB_NDN_N.cpp
        src/Natural/DIV_NN_Dk.cpp
        src/Natural/DIV_NN_N.cpp
        src/Natural/MOD_NN_N.cpp
        src/Natural/GCF_NN_N.cpp
        src/Natural/LCM_NN_N.cpp
        src/Integer/INTEGER.cpp
        src/Integer/ABS_Z_Z.cpp
        src/Integer/POZ_Z_D.cpp
        src/Integer/MUL_ZM_Z.cpp
        src/Integer/TRANS_N_Z.cpp
        src/Integer/TRANS_Z_N.cpp
        src/Integer/ADD_ZZ_Z.cpp
)
target_include_directories(cls PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(main examples/main.cpp)
target_link_libraries(main cls)