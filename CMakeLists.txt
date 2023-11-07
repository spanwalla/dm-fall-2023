cmake_minimum_required(VERSION 3.25)
project(dm_fall_2023 VERSION 0.2)

set(CMAKE_CXX_STANDARD 20)
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
        src/Integer/MUL_ZZ_Z.cpp
        src/Integer/DIV_ZZ_Z.cpp
        src/Integer/SUB_ZZ_Z.cpp
        src/Integer/MOD_ZZ_Z.cpp
        src/Rational/RATIONAL.cpp
		    src/Rational/RED_Q_Q.cpp
        src/Rational/INT_Q_B.cpp
        src/Rational/TRANS_Z_Q.cpp
        src/Rational/TRANS_Q_Z.cpp
        src/Rational/ADD_QQ_Q.cpp
        src/Rational/SUB_QQ_Q.cpp
        src/Rational/MUL_QQ_Q.cpp
        src/Rational/DIV_QQ_Q.cpp
        src/Polynomial/POLYNOMIAL.cpp
		    src/Polynomial/MUL_PQ_P.cpp
		    src/Polynomial/MUL_Pxk_P.cpp
  		  src/Polynomial/LED_P_Q.cpp
        src/Polynomial/DEG_P_N.cpp
)
target_include_directories(cls PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(calculator examples/calculator.cpp)
target_link_libraries(calculator cls)

add_executable(main examples/main.cpp)
target_link_libraries(main cls)

add_subdirectory(external/googletest)

add_executable(test tests/natural_test.cpp)
target_link_libraries(test cls gtest gmock pthread)
