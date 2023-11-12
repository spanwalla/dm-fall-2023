//created by Sofya Bodareva on 08.11.23
//модульное тестирование функций целых чисел

#include <gtest/gtest.h>
#include "../include/CLS.h"

// Тесты для функции ABS_Z_Z - абсолютная величина числа

// №1 - число положительное

TEST(ABS_Z_Z_TEST, Abs_pozitive_num){
    Integer i(5);

    ASSERT_TRUE(i.ABS_Z_Z() == Integer(5));
}

// №2 - число отрицательное

TEST(ABS_Z_Z_TEST, Abs_negative_num){
    Integer i(-10);

    ASSERT_TRUE(i.ABS_Z_Z() == Integer(10));
}

// №3 - число 0

TEST(ABS_Z_Z_TEST, Abs_for_zero){
    Integer i(0);

    ASSERT_TRUE(i.ABS_Z_Z() == Integer(0));
}


/*Тесты для функции POZ_Z_D - определение положительности числа 
(2 - положительное, 0 - ноль, 1 - отрицательное)*/

// №4 - положительное число

TEST(POZ_Z_D_TEST, Poz_pozitive_num){
    Integer i(353);

    ASSERT_TRUE(i.POZ_Z_D() == 2);
}

// №5 - отрицательное число 

TEST(POZ_Z_D_TEST, Poz_negative_num){
    Integer i(-24);

    ASSERT_TRUE(i.POZ_Z_D() == 1);
}

// №6 - число 0

TEST(POZ_Z_D_TEST, Poz_for_zero){
    Integer i(0);

    ASSERT_TRUE(i.POZ_Z_D() == 0);
}


// Тесты для функции MUL_ZM_Z - умножение целого на (-1)

// №7 - число положительное

TEST(MUL_ZM_Z_TEST, Mul_zm_pozitive_num){
    Integer i(52);

    i.MUL_ZM_Z();

    ASSERT_TRUE(i == Integer(-52));
}

// №8 - число отрицательное

TEST(MUL_ZM_Z_TEST, Mul_zm_negative){
    Integer i(-100);

    i.MUL_ZM_Z();

    ASSERT_TRUE(i == Integer(100));
}

// №9 - число 0

TEST(MUL_ZM_Z_TEST, Mul_zm_for_zero){
    Integer i(0);

    i.MUL_ZM_Z();

    ASSERT_TRUE(i == Integer(0));
}


// Тесты для функции TRANS_N_Z - преобразование натурального в целое

// №10 - число не 0

TEST(TRANS_N_Z_TEST, Trans_n_z_pozitive){
    Natural n(423);

    Integer i;

    ASSERT_TRUE(i.TRANS_N_Z(n) == Integer(423));
}

// №11 - число 0

TEST(TRANS_N_Z_TEST, Trans_n_z_zero){
    Natural n(0);

    Integer i;

    ASSERT_TRUE(i.TRANS_N_Z(n) == Integer(0));
}


// Тесты функции TRANS_Z_N - преобразование целого в натуральное

// №12 - число положительное

TEST(TRANS_Z_N_TEST, Trans_z_n_pozitive){
    Integer i(100);

    ASSERT_TRUE(i.TRANS_Z_N() == Natural(100));
}

// №13 - число 0

TEST(TRANS_Z_N_TEST, Trans_z_n_zero){
    Integer i(0);

    ASSERT_TRUE(i.TRANS_Z_N() == Natural(0));
}

// №14 - отрицательное число 

TEST(TRANS_Z_N_TEST, Trans_z_n_error){
    Integer i(-754);

    ASSERT_THROW(i.TRANS_Z_N(), std::logic_error);
}


// Тесты для функции ADD_ZZ_Z - сложение целых чисел

// №15 - отрицательное и положительное с положительным результатом

TEST(ADD_ZZ_Z_TEST, Add_neg_poz_poz){
    Integer i1(-20);
    Integer i2(30);

    i1.ADD_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(10));
}

// №16 - отрицательно и положительное с отрицательным результатом

TEST(ADD_ZZ_Z_TEST, Add_neg_poz_neg){
    Integer i1(-867);
    Integer i2(67);

    i1.ADD_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(-800));
}

// №17 - положительное и отрицательное с отрицательным результатом

TEST(ADD_ZZ_Z_TEST, Add_poz_neg_neg){
    Integer i1(30);
    Integer i2(-40);

    i1.ADD_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(-10));
}

// №18 - положительное и отрицательное с положительным результатом

TEST(ADD_ZZ_Z_TEST, Add_poz_neg_poz){
    Integer i1(50);
    Integer i2(-5);

    i1.ADD_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(45));
}

// №19 - положительное и положительное

TEST(ADD_ZZ_Z_TEST, Add_poz_poz){
    Integer i1(325);
    Integer i2(34);

    i1.ADD_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(359));
}

// №20 - отрицательное и отрицательное

TEST(ADD_ZZ_Z_TEST, Add_neg_neg){
    Integer i1(-685);
    Integer i2(-434);

    i1.ADD_ZZ_Z(i2);

    ASSERT_TRUE (i1 == Integer(-1119));
}

// №21 - общий случай

TEST(ADD_ZZ_Z_TEST, Add_general_case){
    Integer i1("3547653984568934658962456892634");
    Integer i2("436236436546463463643623643654649894017446932369193597100536268");

    i1.ADD_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer("436236436546463463643623643654653441671431501303852559557428902"));
}


// Тесты для функции SUB_ZZ_Z - вычитание целых чисел

// №22 - отрицательное и отрицательное с отрицательным результатом

TEST(SUB_ZZ_Z_TEST, Sub_neg_neg_neg){
    Integer i1(-500);
    Integer i2(-150);

    i1.SUB_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(-350));
}

// №23 - отрицательное и отрицательное с положительным результатом

TEST(SUB_ZZ_Z_TEST, Sub_neg_neg_poz){
    Integer i1(-232);
    Integer i2(-400);

    i1.SUB_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(168));
}

// №24 - положительное и положительное с положительным результатом

TEST(SUB_ZZ_Z_TEST, Sub_poz_poz_poz){
    Integer i1(745);
    Integer i2(200);

    i1.SUB_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(545));
}

// №25 - положительное и положительное с отрицательным результатом

TEST(SUB_ZZ_Z_TEST, Sub_poz_poz_neg){
    Integer i1(83);
    Integer i2(980);

    i1.SUB_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(-897));
}

// №26 - отрицательное и положительное

TEST(SUB_ZZ_Z_TEST, Sub_neg_poz){
    Integer i1(-900);
    Integer i2(750);

    i1.SUB_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(-1650));
}

// №27 - положительное и отрицательное

TEST(SUB_ZZ_Z_TEST, Sub_poz_neg){
    Integer i1(834);
    Integer i2(-200);

    i1.SUB_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(1034));
}

// №28 - общий случай

TEST(SUB_ZZ_Z_TEST, Sub_general_case){
    Integer i1("45863486709349054679074697924902734286943");
    Integer i2("23492379523908437974239");

    i1.SUB_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer("45863486709349054655582318400994296312704"));
}


// Тесты для функции MUL_ZZ_Z - умножение целых чисел

// №29 - положительное и положительное

TEST(MUL_ZZ_Z_TEST, Mul_poz_poz){
    Integer i1(5);
    Integer i2(10);

    i1.MUL_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(50));
}

// №30 - отрицательное и отрицательное

TEST(MUL_ZZ_Z_TEST, Mul_neg_neg){
    Integer i1(-30);
    Integer i2(-40);

    i1.MUL_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(1200));
}

// №31 - положительное и отрицательное

TEST(MUL_ZZ_Z_TEST, Mul_poz_neg){
    Integer i1(100);
    Integer i2(-40);

    i1.MUL_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(-4000));
}

// №32 - умножение на 0

TEST(MUL_ZZ_Z_TEST, Mul_zero){
    Integer i1("43235");
    Integer i2("0");

    i1.MUL_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer(0));
}

// №33 - общий случай

TEST(MUL_ZZ_Z_TEST, Mul_general_case){
    Integer i1("38275893645848659864958634");
    Integer i2("-23597239857347603");

    i1.MUL_ZZ_Z(i2);

    ASSERT_TRUE(i1 == Integer("-903205443115417854614416047596114554054302"));
}


/*Тесты для функции DIV_ZZ_Z - частное от деления целого на целое
(делитель отличен от нуля)*/

// №34 - первое равно 0

TEST(DIV_ZZ_Z_TEST, Div_first_zero){
    Integer i1(0);
    Integer i2(52353);

    ASSERT_TRUE(i1.DIV_ZZ_Z(i2) == Integer(0));
}

// №35 - деление на 0

TEST(DIV_ZZ_Z_TEST, Div_error){
    Integer i1(967856);
    Integer i2(0);

    ASSERT_THROW(i1.DIV_ZZ_Z(i2), std::logic_error);
}

// №36 - первое равно 1

TEST(DIV_ZZ_Z_TEST, Div_first_one){
    Integer i1(1);
    Integer i2(43234);

    ASSERT_TRUE(i1.DIV_ZZ_Z(i2) == Integer(0));
}

// №37 - второе равно 1

TEST(DIV_ZZ_Z_TEST, Div_second_one){
    Integer i1(3534);
    Integer i2(1);

    ASSERT_TRUE(i1.DIV_ZZ_Z(i2) == Integer(3534));
}

// №38 - числа равны

TEST(DIV_ZZ_Z_TEST, Div_equal_numbers){
    Integer i1(24);
    Integer i2(24);

    ASSERT_TRUE(i1.DIV_ZZ_Z(i2) == Integer(1));
}

// №39 - общий случай

TEST(DIV_ZZ_Z_TEST, Div_general_case){
    Integer i1("6346346345634675896");
    Integer i2("2579605967");

    ASSERT_TRUE(i1.DIV_ZZ_Z(i2) == Integer("2460199901"));
}


/*Тесты для функции MOD_ZZ_Z - остаток от деления целого на целое
(делитель отличен от нуля)*/

// №40 - первое равно 0

TEST(MOD_ZZ_Z_TEST, Mod_first_zero){
    Integer i1(0);
    Integer i2(4235);

    ASSERT_TRUE(i1.MOD_ZZ_Z(i2) == Integer(0));
}

// №41 - второе равно 0

TEST(MOD_ZZ_Z_TEST, Mod_error){
    Integer i1(53);
    Integer i2(0);

    ASSERT_THROW(i1.MOD_ZZ_Z(i2), std::logic_error);
}

// №42 - первое равно 1

TEST(MOD_ZZ_Z_TEST, Mod_first_one){
    Integer i1("1");
    Integer i2("23423");

    ASSERT_TRUE(i1.MOD_ZZ_Z(i2) == Integer(1));
}

// №43 - второе равно 1

TEST(MOD_ZZ_Z_TEST, Mod_second_two){
    Integer i1(3453);
    Integer i2(1);

    ASSERT_TRUE(i1.MOD_ZZ_Z(i2) == Integer(0));
}

// №44 - первое меньше второго

TEST(MOD_ZZ_Z_TEST, Mod_first_less_than_second){
    Integer i1(35);
    Integer i2(243);

    ASSERT_TRUE(i1.MOD_ZZ_Z(i2) == Integer(35));
}

// №45 - числа равны

TEST(MOD_ZZ_Z_TEST, Mod_equal_numbers){
    Integer i1("532364");
    Integer i2("532364");

    ASSERT_TRUE(i1.MOD_ZZ_Z(i2) == Integer(0));
}

// №46 - общий случай

TEST(MOD_ZZ_Z_TEST, Mod_general_case){
    Integer i1("542363463463452");
    Integer i2("3058420856");

    ASSERT_TRUE(i1.MOD_ZZ_Z(i2) == Integer("1459385548"));
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
