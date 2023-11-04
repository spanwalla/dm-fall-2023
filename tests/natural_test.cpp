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


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}