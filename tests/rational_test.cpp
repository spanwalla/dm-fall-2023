//created by Sofya Bodareva on 12.11.23
//модульное тестирование функций рациональных чисел

#include <gtest/gtest.h>
#include "../include/CLS.h"


// Тесты для функции REQ_Q_Q_ - сокращение дроби

// №1 - несократимая дробь

TEST(REQ_Q_Q_TEST, Req_irreducible_fractoin){
    Rational r ("17/3");

    r.RED_Q_Q();

    ASSERT_TRUE(r == Rational("17/3"));
}

// №2 - в знаменателе останется 1

TEST(REQ_Q_Q_TEST, Req_denominator_become_1){
    Rational r("39/13");

    r.RED_Q_Q();

    ASSERT_TRUE(r == Rational("3/1"));
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}