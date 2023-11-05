#include <gtest/gtest.h>
#include "../include/CLS.h"


// Тесты для функции COM_NN_D - сравнение двух чисел

// №1 - в первом числе больше цифр, чем во втором

TEST(First_More_Digits, COM_NN_D_TEST){
    Natural n1 ("12384723");
    Natural n2 ("342524");

    ASSERT_EQ(n1.COM_NN_D(n2), 2);
}


// №2 - в числах одинаковое количество цифр, но первое больше

TEST(First_Greater_And_Same_Number_Of_Digits, COM_NN_D_TEST){
    Natural n1("5555555555555");
    Natural n2("4444444444444");

    ASSERT_EQ(n1.COM_NN_D(n2), 2);
}


// №3 - числа равны
TEST(Equal_Numbers, COM_NN_D_TEST){
    Natural n1("342353454");
    Natural n2("342353454");

    ASSERT_EQ(n1.COM_NN_D(n2), 0);
}


// №4 - во втором числе больше цифр, чем в первом

TEST(Second_More_Digits, COM_NN_D_TEST){
    Natural n1("5439");
    Natural n2("738205");

    ASSERT_EQ(n1.COM_NN_D(n2), 1);
}


// №5 - в числах одинаковое количество цифр, но второе больше

TEST(Second_Greater_And_Same_Number_Of_Digits, COM_NN_D_TEST){
    Natural n1("8888888");
    Natural n2("8888889");

    ASSERT_EQ(n1.COM_NN_D(n2), 1);
}


// Тесты для функции NZER_N_B - проверка на ноль

// №6 - число равно 0

TEST(Number_Is_Zero, NZER_N_B_TEST){
    Natural n("0");

    ASSERT_EQ(n.NZER_N_B(), false);
}

// №7 - число не равно 0

TEST(Number_Is_Not_Zero, NZER_N_B_TEST){
    Natural n("3856458436856238456236562");

    ASSERT_EQ(n.NZER_N_B(), true);
}


// Тесты для функции ADD_1N_N - прибавление 1

// №8 - без переноса разрядов

TEST(Add_Without_Offset, ADD_1N_N_TEST){
    Natural n(1000);

    n.ADD_1N_N();

    ASSERT_TRUE(n == Natural(1001));
}

// №9 - с переносом разряда без увеличения количества цифр

TEST(Add_With_Offset_Inplace, ADD_1N_N_TEST){
    Natural n(1999);
    
    n.ADD_1N_N();

    ASSERT_TRUE(n == Natural(2000));
}

// №10 - с переносом разряда с увеличением количества цифр

TEST(Add_With_Offset_Not_Inplace, ADD_1N_N_TEST){
    Natural n(9999999999);

    n.ADD_1N_N();

    ASSERT_TRUE(n == Natural(10000000000));
}

// №11 - прибавление к 0

TEST(Add_To_Zero, ADD_1N_N_TEST){
    Natural n;

    n.ADD_1N_N();

    ASSERT_TRUE(n == Natural(1));
}


// Тесты для функции ADD_NN_N - сложение натуральных чисел

// №12 - без переноса разряда

TEST(Add_without_Offset, ADD_NN_N_TEST){
    Natural n1 (123000);
    Natural n2 (6423);

    n1.ADD_NN_N(n2);

    ASSERT_TRUE(n1 == Natural(129423));
}

//№13 - с переносом разряда без увеличвания количества цифр

TEST(Add_with_Offset_Inplace, ADD_NN_N_TEST){
    Natural n1(19999);
    Natural n2(2);

    n1.ADD_NN_N(n2);

    ASSERT_TRUE(n1 == Natural(20001));
}

// №14 - с переносом разряда с увеличением количества цифр

TEST(Add_With_Offset_not_Inplace, ADD_NN_N_TEST){
    Natural n1(99);
    Natural n2(6);

    n1.ADD_NN_N(n2);

    ASSERT_TRUE(n1 == Natural(105));
}

// №15 - без переноса разряда с увеличением количества цифр

TEST(Add_without_offset_But_Not_Inplace, ADD_NN_N_TEST){
    Natural n1(64);
    Natural n2(100);

    n1.ADD_NN_N(n2);

    ASSERT_TRUE(n1 == Natural(164));
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}