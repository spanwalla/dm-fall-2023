// Created by Sofya Bodareva (2382) on 06.11.2023.
// Модульное тестирование функций натуральных чисел.

#include <gtest/gtest.h>
#include "../include/CLS.h"


// Тесты для функции COM_NN_D - сравнение двух чисел

// №1 - в первом числе больше цифр, чем во втором

TEST(COM_NN_D_TEST, First_more_digits){
    Natural n1 ("12384723");
    Natural n2 ("342524");

    ASSERT_EQ(n1.COM_NN_D(n2), 2);
}


// №2 - в числах одинаковое количество цифр, но первое больше

TEST(COM_NN_D_TEST, First_greater_and_same_number_of_digits){
    Natural n1("5555555555555");
    Natural n2("4444444444444");

    ASSERT_EQ(n1.COM_NN_D(n2), 2);
}


// №3 - числа равны
TEST(COM_NN_D_TEST, Equal_numbers){
    Natural n1("342353454");
    Natural n2("342353454");

    ASSERT_EQ(n1.COM_NN_D(n2), 0);
}


// №4 - во втором числе больше цифр, чем в первом

TEST(COM_NN_D_TEST, Second_more_digits){
    Natural n1("5439");
    Natural n2("738205");

    ASSERT_EQ(n1.COM_NN_D(n2), 1);
}


// №5 - в числах одинаковое количество цифр, но второе больше

TEST(COM_NN_D_TEST, Second_greater_and_same_number_of_digits){
    Natural n1("8888888");
    Natural n2("8888889");

    ASSERT_EQ(n1.COM_NN_D(n2), 1);
}


// Тесты для функции NZER_N_B - проверка на ноль

// №6 - число равно 0

TEST(NZER_N_B_TEST, Number_is_zero){
    Natural n("0");

    ASSERT_EQ(n.NZER_N_B(), false);
}

// №7 - число не равно 0

TEST(NZER_N_B_TEST, Number_is_not_zero){
    Natural n("3856458436856238456236562");

    ASSERT_EQ(n.NZER_N_B(), true);
}


// Тесты для функции ADD_1N_N - прибавление 1

// №8 - без переноса разрядов

TEST(ADD_1N_N_TEST, Add_1_without_offset){
    Natural n(1000);

    n.ADD_1N_N();

    ASSERT_TRUE(n == Natural(1001));
}

// №9 - с переносом разряда без увеличения количества цифр

TEST(ADD_1N_N_TEST, Add_1_with_offset_inplace){
    Natural n(1999);
    
    n.ADD_1N_N();

    ASSERT_TRUE(n == Natural(2000));
}

// №10 - с переносом разряда с увеличением количества цифр

TEST(ADD_1N_N_TEST, Add_1_with_offset_not_inplace){
    Natural n(9999999999);

    n.ADD_1N_N();

    ASSERT_TRUE(n == Natural(10000000000));
}

// №11 - прибавление к 0

TEST(ADD_1N_N_TEST, Add_1_to_zero){
    Natural n;

    n.ADD_1N_N();

    ASSERT_TRUE(n == Natural(1));
}


// Тесты для функции ADD_NN_N - сложение натуральных чисел

// №12 - без переноса разряда

TEST(ADD_NN_N_TEST, Add_without_offset){
    Natural n1 (123000);
    Natural n2 (6423);

    n1.ADD_NN_N(n2);

    ASSERT_TRUE(n1 == Natural(129423));
}

//№13 - с переносом разряда без увеличения количества цифр

TEST(ADD_NN_N_TEST, Add_with_offset_inplace){
    Natural n1(19999);
    Natural n2(2);

    n1.ADD_NN_N(n2);

    ASSERT_TRUE(n1 == Natural(20001));
}

// №14 - с переносом разряда с увеличением количества цифр

TEST(ADD_NN_N_TEST, Add_with_offset_not_inplace){
    Natural n1(99);
    Natural n2(6);

    n1.ADD_NN_N(n2);

    ASSERT_TRUE(n1 == Natural(105));
}

// №15 - без переноса разряда с увеличением количества цифр

TEST(ADD_NN_N_TEST, Add_without_offset_but_not_inplace){
    Natural n1(64);
    Natural n2(100);

    n1.ADD_NN_N(n2);

    ASSERT_TRUE(n1 == Natural(164));
}


// Тесты для функции SUB_NN_N - вычитание для случая с неотрицательным результатом

// №16 - без займа разрядов и уменьшения количества цифр

TEST(SUB_NN_N_TEST, Sub_without_offset_and_loss_digits){
    Natural n1("438293550345");
    Natural n2("342");

    n1.SUB_NN_N(n2);

    ASSERT_TRUE(n1 == Natural("438293550003"));
}

// №17 - с займом разрядов с уменьшением количества цифр

TEST(SUB_NN_N_TEST, Sub_with_offset_without_loss_digits){
    Natural n1("83883494938");
    Natural n2("19");

    n1.SUB_NN_N(n2);

    ASSERT_TRUE(n1 == Natural("83883494919"));
}

// №18 - с займом разрядов и с уменьшением количества цифр

TEST(SUB_NN_N_TEST, Sub_with_offset_and_loss_digits){
    Natural n1("1000000");
    Natural n2("5437");

    n1.SUB_NN_N(n2);

    ASSERT_TRUE(n1 == Natural(994563));
}

// №19 - числа равны

TEST(SUB_NN_N_TEST, SUB_NN_N_TESTSub_equal_digits){
    Natural n1("54839");
    Natural n2("54839");

    n1.SUB_NN_N(n2);

    ASSERT_TRUE(n1 == Natural());
}

// №20 - без занимания разрядов с уменьшением количества цифр

TEST(SUB_NN_N_TEST, Sub_without_offset_with_loss_digits){
    Natural n1("245");
    Natural n2("240");

    n1.SUB_NN_N(n2);

    ASSERT_TRUE(n1 == Natural(5));
}

// №21 - второе больше первого

TEST(SUB_NN_N_TEST, Sub_error){
    Natural n1(15);
    Natural n2(21);

    ASSERT_THROW(n1.SUB_NN_N(n2), std::logic_error);
}


 // Тесты для функции MUL_ND_N - умножение натурального на цифру

// №22 - умножение на 0

TEST(MUL_ND_N_TEST, MulND_digit_is_zero){
    Natural n("4583454385925689265892");

    n.MUL_ND_N(0);

    ASSERT_TRUE(n == Natural(0));
}

// №23 - умножение на 1

TEST(MUL_ND_N_TEST, MulND_digit_is_one){
    Natural n("4525");

    n.MUL_ND_N(1);

    ASSERT_TRUE(n == Natural(4525));
}

// №24 - умножение натурального нуля на цифру

TEST(MUL_ND_N_TEST, MulND_natural_is_zero){
    Natural n(0);

    n.MUL_ND_N(4);

    ASSERT_TRUE(n == Natural(0));
}

// №25 - умножение без увеличения количества цифр

TEST(MUL_ND_N_TEST, MulND_inplace){
    Natural n(15);

    n.MUL_ND_N(5);

    ASSERT_TRUE(n == Natural(75));
}

// №26 - умножение с увеличением количества цифр

TEST(MUL_ND_N_TEST, MulND_not_inplace){
    Natural n(21);

    n.MUL_ND_N(5);

    ASSERT_TRUE(n == Natural(105));
}

// №27 - попытка умножения на отрицательное

TEST(MUL_ND_N_TEST, MulND_negative_number){
    Natural n(5435);

    n.MUL_ND_N(-3);

    ASSERT_TRUE(n == Natural(5435));
}

// №28 - попытка умножения не на цифру

TEST(MUL_ND_N_TEST, MulND_not_digit){
    Natural n(5235);

    n.MUL_ND_N(4533);

    ASSERT_TRUE(n == Natural(5235));
}


// Тесты для функции MUL_Nk_N - умножение натурального на 10^k

// №29 - число равно 0

TEST(MUL_Nk_N_TEST, MulNk_natural_is_zero){
    Natural n(0);

    n.MUL_Nk_N(3942);

    ASSERT_TRUE(n == Natural(0));
}

// №30 - k равно 0

TEST(MUL_Nk_N_TEST, MulNk_k_is_zero){
    Natural n(43);

    n.MUL_Nk_N(0);

    ASSERT_TRUE(n == Natural(43));
}

// №31 - общий случай

TEST(MUL_Nk_N_TEST, MulNk_general_case){
    Natural n(1223);

    n.MUL_Nk_N(5);

    ASSERT_TRUE(n == Natural("122300000"));
}


// Тесты функции MUL_NN_N - умножение натуральных чисел

// №32 - без увеличения количества цифр

TEST(MUL_NN_N_TEST, Mul_inplace){
    Natural n1(33);
    Natural n2(3);

    n1.MUL_NN_N(n2);

    ASSERT_TRUE(n1 == Natural(99));
}

// №33 - с увеличением количества цифр

TEST(MUL_NN_N_TEST, Mul_not_inplace){
    Natural n1(66);
    Natural n2(6);

    n1.MUL_NN_N(n2);

    ASSERT_TRUE(n1 == Natural(396));
}

// №34 - общий случай

TEST(MUL_NN_N_TEST, Mul_general_case){
    Natural n1("53485738975");
    Natural n2("634683463");

    n1.MUL_NN_N(n2);

    ASSERT_TRUE(n1 == Natural("33946514033767070425"));
}


/* Тесты для функции SUB_NDN_N - вычитание из натурального другого натурального
домноженного на цифру для случая с неотрицательным результатом */

// №35 - после умножения на цифру вычитаемое становится больше уменьшаемого

TEST(SUB_NDN_N_TEST, SubNDN_error){
    Natural n1(46);
    Natural n2(15);

    ASSERT_THROW(n1.SUB_NDN_N(n2, 4), std::logic_error);
}

// №36 - общий случай

TEST(SUB_NDN_N_TEST, SubNDN_general_case){
    Natural n1("3458734753857348597234");
    Natural n2("5438579");

    n1.SUB_NDN_N(n2, 5);

    ASSERT_TRUE(n1 == Natural("3458734753857321404339"));
}

// №37 - умножение на 0

TEST(SUB_NDN_N_TEST, Sub_NDN_digit_is_zero){
    Natural n1("242344235");
    Natural n2("243");

    n1.SUB_NDN_N(n2, 0);

    ASSERT_TRUE(n1 == Natural("242344235"));
}


/* Тесты для функции DIV_NN_Dk - вычисление первой цифры деления большего натурального
 на меньшее, домноженное на 10^k, где k - номер позиции этой цифры */

// №38 - числа равны

TEST(DIV_NN_Dk_TEST, DivDk_equal_naturals){
    Natural n1(100);
    Natural n2(100);

    ASSERT_TRUE(n1.DIV_NN_Dk(n2) == Natural(1));
}

// №39 - деление на 1

TEST(DIV_NN_Dk_TEST, DivDk_second_is_one){
    Natural n1(153);
    Natural n2(1);

    ASSERT_TRUE(n1.DIV_NN_Dk(n2) == Natural(100));
}

// №40 - делитель больше делимого 

TEST(DIV_NN_Dk_TEST, Div_Dk_error){
    Natural n1(132);
    Natural n2(5452);

    ASSERT_THROW(n1.DIV_NN_Dk(n2), std::logic_error);
}

// №41 - общий случай

TEST(DIV_NN_Dk_TEST, Div_Dk_general_case){
    Natural n1("52352354365765239789353453");
    Natural n2("32545768743652356");

    ASSERT_TRUE(n1.DIV_NN_Dk(n2) == Natural("1000000000"));
}


/* Тесты функции DIV_NN_N - неполное частное от деления первого натурального числа
 на второе с остатком (делитель отличен от нуля) */

// №42 - первое меньше второго

TEST(DIV_NN_N_TEST, Div_first_less_than_second){
    Natural n1(10);
    Natural n2(64);

    ASSERT_TRUE(n1.DIV_NN_N(n2) == Natural(0));
}

// №43 - первое равно 0

TEST(DIV_NN_N_TEST, Div_first_is_zero){
    Natural n1(0);
    Natural n2(354325);

    ASSERT_TRUE(n1.DIV_NN_N(n2) == n1);
}

// №44 - числа равны

TEST(DIV_NN_N_TEST, Div_equal_naturals){
    Natural n1(342);
    Natural n2(342);

    ASSERT_TRUE(n1.DIV_NN_N(n2) == Natural(1));
}

// №45 - второе равно 1

TEST(DIV_NN_N_TEST, Div_second_is_one){
    Natural n1(769);
    Natural n2(1);

    ASSERT_TRUE(n1.DIV_NN_N(n2) == n1);
}

// №46 - деление на 0

TEST(DIV_NN_N_TEST, Div_error){
    Natural n1(352);
    Natural n2(0);

    ASSERT_THROW(n1.DIV_NN_N(n2), std::logic_error);
}

// №47 - общий случай

TEST(DIV_NN_N_TEST, Div_general_case){
    Natural n1("5348758364583465364534");
    Natural n2("9534775");

    ASSERT_TRUE(n1.DIV_NN_N(n2) == Natural("560973737144658"));
}


/*Тесты функции MOD_NN_N - остаток от деления первого натурального числа
на второе натуральное (делитель отличен от нуля)*/

// №48 - первое меньше второго

TEST(MOD_NN_N_TEST, Mod_first_less_than_second){
    Natural n1(345);
    Natural n2(79891);

    ASSERT_TRUE(n1.MOD_NN_N(n2) == n1);
}

// №49 - первое равно 0

TEST(MOD_NN_N_TEST, Mod_first_is_zero){
    Natural n1("0");
    Natural n2("54522542");

    ASSERT_TRUE(n1.MOD_NN_N(n2) == n1);
}

// №50 - числа равны

TEST(MOD_NN_N_TEST, Mod_equal_naturals){
    Natural n1(653);
    Natural n2(653);

    ASSERT_TRUE(n1.MOD_NN_N(n2) == Natural(0));
}

// №51 - второе равно 1

TEST(MOD_NN_N_TEST, Mod_second_is_one){
    Natural n1(46463);
    Natural n2(1);

    ASSERT_TRUE(n1.MOD_NN_N(n2) == Natural(0));
}

// №52 - второе равно 0

TEST(MOD_NN_N_TEST, Mod_error){
    Natural n1(453);
    Natural n2(0);

    ASSERT_THROW(n1.MOD_NN_N(n2), std::logic_error);
}

//  №53 - общий случай

TEST(MOD_NN_N_TEST, Mod_general_case){
    Natural n1("94756347864263443634634523895892365");
    Natural n2("6345683475986485684");

    ASSERT_TRUE(n1.MOD_NN_N(n2) == Natural("1959217459544967717"));
}


//Тесты для функции GCF_NN_N - НОД натуральных чисел

// №54 - Оба числа равны 0

TEST(GSF_NN_N_TEST, Gcf_error){
    Natural n1(0);
    Natural n2(0);

    ASSERT_THROW(n1.GCF_NN_N(n2), std::logic_error);
}

// №55 - одно из чисел равно 1

TEST(GSF_NN_N_TEST, Gcf_with_one){
    Natural n1(6345);
    Natural n2(1);

    ASSERT_TRUE(n1.GCF_NN_N(n2) ==  n2);
}

// №56 - первое число равно 0

TEST(GSF_NN_N_TEST, Gcf_first_is_zero){
    Natural n1(0);
    Natural n2(4235);

    ASSERT_TRUE(n1.GCF_NN_N(n2) == n2);
}

// №57 - числа равны

TEST(GSF_NN_N_TEST, Gcf_equal_naturals){
    Natural n1(785);
    Natural n2(785);

    ASSERT_TRUE(n1.GCF_NN_N(n2) == n1);
}

// №58 - одно из чисел кратно другому

TEST(GSF_NN_N_TEST, Gcf_one_number_is_a_multiple_of_another){
    Natural n1(30);
    Natural n2(210);

    ASSERT_TRUE(n1.GCF_NN_N(n2) == n1);
}

// №59 - числа взаимно простые

TEST(GSF_NN_N_TEST, Gcf_mutually_prime_numbers){
    Natural n1(101);
    Natural n2(13);

    ASSERT_TRUE(n1.GCF_NN_N(n2) == Natural(1));
}

// №60 - общий случай

TEST(GSF_NN_N_TEST, Gcf_general_case){
    Natural n1("97578237586235623787509234643634647563783684634");
    Natural n2("13452759874967396");

    ASSERT_TRUE(n1.GCF_NN_N(n2) == Natural(2));
}


// Тесты для функции LCM_NN_N - НОК натуральных чисел

// №61 - одно из чисел 0

TEST(LCM_NN_N_TEST, Lcm_one_zero){
    Natural n1("345436");
    Natural n2(0);

    ASSERT_TRUE(n1.LCM_NN_N(n2) == n2);
}

// №62 - оба числа 0

TEST(LCM_NN_N_TEST, Lcm_error){
    Natural n1(0);
    Natural n2(0);

    ASSERT_THROW(n1.LCM_NN_N(n2), std::logic_error);
}

// №63 - одно из чисел равно 1

TEST(LCM_NN_N_TEST, Lcm_one_is_one){
    Natural n1("156876");
    Natural n2(1);

    ASSERT_TRUE(n1.LCM_NN_N(n2) == n1);
}

// №64 - числа равны

TEST(LCM_NN_N_TEST, Lcm_equal_naturals){
    Natural n1(987);
    Natural n2(987);

    ASSERT_TRUE(n1.LCM_NN_N(n2) == n1);
}

// №65 - одно из чисел кратно другому

TEST(LCM_NN_N_TEST, Lcm_one_number_is_a_multiple_of_another){
    Natural n1(256);
    Natural n2(64);

    ASSERT_TRUE(n1.LCM_NN_N(n2) == n1);
}

// №66 - числа взаимно простые

TEST(LCM_NN_N_TEST, Lcm_mutually_prime_numbers){
    Natural n1(13);
    Natural n2(17);

    ASSERT_TRUE(n1.LCM_NN_N(n2) == Natural(221));
}

// №67 - общий случай

TEST(LCM_NN_N_TEST, Lcm_general_case){
    Natural n1("2397592375972364");
    Natural n2("634663264657547879987");

    ASSERT_TRUE(n1.LCM_NN_N(n2) == Natural("1521663804652667493929718185900679268"));
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}