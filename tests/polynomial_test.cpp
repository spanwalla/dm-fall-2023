// Created by Sofya Bodareva (2382) on 13.11.2023.
// Модульное тестирование функций многочленов чисел.

#include <gtest/gtest.h>
#include "../include/CLS.h"


// Тесты для функции ADD_PP_P - сложение многочленов

// №1 - степени многочленов не равны

TEST(ADD_PP_P_TEST, Add_diff_deg){
    Polynomial p1 ("x^2+x");
    Polynomial p2 ("5x+2");

    p1.ADD_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("x^2+6x+2"));
}

// №2 - старшая степень пропадает

TEST(ADD_PP_P_TEST, Add_loss_high_deg){
    Polynomial p1 ("-x^3+x^2-4");
    Polynomial p2 ("x^3-7");

    p1.ADD_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("x^2 -11"));
}

// №3 - многочлены равны, коэффициенты противоположны

TEST(ADD_PP_P_TEST, Add_equal_deg_opposite_coeff){
    Polynomial p1 ("-5x^2+6x-1");
    Polynomial p2 ("5x^2-6x+1");

    p1.ADD_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("0"));
}

// №4 - сложение с нулем

TEST(ADD_PP_P_TEST, Add_zero){
    Polynomial p1 ("x^5-x^4+7x");
    Polynomial p2 ("0");

    p1.ADD_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("x^5-x^4+7x"));
}

// №5 - общий случай

TEST(ADD_PP_P_TEST, Add_general_case){
    Polynomial p1 ("x^7-x^3+17x^2+20");
    Polynomial p2 ("7x^4-3");

    p1.ADD_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("x^7+7x^4-x^3+17x^2+17"));
}


// Тесты для функции SUB_PP_P - вычитание многочленов

// №6 - старшая степень пропадает

TEST(SUB_PP_P_TEST, Sub_loss_high_deg){
    Polynomial p1("x^5+x^2+2");
    Polynomial p2("x^5+x+6");

    p1.SUB_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("x^2-x-4"));
}

// №7 - многочлены равны

TEST(SUB_PP_P_TEST, Sub_equal_pol){
    Polynomial p1("7x^2+9x-4");
    Polynomial p2("7x^2+9x-4");

    p1.SUB_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("0"));
}

// №8 - вычитание 0

TEST(SUB_PP_P_TEST, Sub_zero){
    Polynomial p1("5x^2+7");
    Polynomial p2("0");

    p1.SUB_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("5x^2+7"));
}

// №9 - вычитание из 0

TEST(SUB_PP_P_TEST, Sub_from_zero){
    Polynomial p1("0");
    Polynomial p2("7x+14");

    p1.SUB_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("-7x-14"));
}

// №10 - степень уменьшаемого меньше степени вычитаемого

TEST(SUB_PP_P_TEST, Sub_first_deg_less){
    Polynomial p1("x+6");
    Polynomial p2("x^3+x^2-7x+6");

    p1.SUB_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("-x^3-x^2+8x"));
}

// №11 - общий случай

TEST(SUB_PP_P_TEST, Sub_general_case){
    Polynomial p1("x^5-3x^2+6x");
    Polynomial p2("x^3-x^2-4");

    p1.SUB_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("x^5-x^3-2x^2+6x+4"));
}


// Тесты для функции MUL_PQ_P - умноежние многочлена на рациональное число

// №12 - умножение на 0

TEST(MUL_PQ_Q_TEST, Mul_pq_zero){
    Polynomial p("x^4+x^2-2");
    Rational r("0");

    p.MUL_PQ_P(r);

    ASSERT_TRUE(p == Polynomial("0"));
}

// №13 - умножение на 1

TEST(MUL_PQ_Q_TEST, Mul_pq_one){
    Polynomial p("x^3-x^2+3x-124");
    Rational r("1");

    p.MUL_PQ_P(r);

    ASSERT_TRUE(p == Polynomial("x^3-x^2+3x-124"));
}

// №14 - умножение на -1

TEST(MUL_PQ_Q_TEST, Mul_pq_neg_one){
    Polynomial p("x^2-x+5");
    Rational r("-1");

    p.MUL_PQ_P(r);

    ASSERT_TRUE(p == Polynomial("-x^2+x-5"));
}

// №15 - умножение на отрицательное

TEST(MUL_PQ_Q_TEST, Mul_pq_neg_rat){
    Polynomial p("2x^3+x^2-15/2x-1");
    Rational r("-5/2");

    p.MUL_PQ_P(r);

    ASSERT_TRUE(p == Polynomial("-5x^3-5/2x^2+75/4x+5/2"));
}

// №16 - умножение на положительное

TEST(MUL_PQ_Q_TEST, Mul_pq_poz_rat){
    Polynomial p("x^4-7x");
    Rational r("16/9");

    p.MUL_PQ_P(r);

    ASSERT_TRUE(p == Polynomial("16/9x^4-112/9x"));
}


//Тесты для функции MUL_Pxk_P - умножение многочлена на x^k

// №17 - k = 0

TEST(MUL_Pxk_P_TEST, MUL_Pxk_zero){
    Polynomial p("x^2+x^3+2x");

    p.MUL_Pxk_P(0);

    ASSERT_TRUE(p == Polynomial("x^2+x^3+2x"));
}

// №18 - k > 0

TEST(MUL_Pxk_P_TEST, MUL_Pxk_not_zero){
    Polynomial p("x^5+x^3-4x");

    p.MUL_Pxk_P(6);

    ASSERT_TRUE(p == Polynomial("x^11+x^9-4x^7"));
}

// Тесты для функции LED_P_Q - старший коэффициент многочлена

// №19 - нулевой многочлен

TEST(LED_P_Q_TEST, Led_zero_pol){
    Polynomial p("0");

    ASSERT_TRUE(p.LED_P_Q() == Rational("0"));
}

// №20 - многочлен нулевой степени

TEST(LED_P_Q_TEST, Led_zero_deg){
    Polynomial p("7");

    ASSERT_TRUE(p.LED_P_Q() == Rational("7"));
}

// №21 - общий случай

TEST(LED_P_Q_TEST, Led_general_case){
    Polynomial p("4x^2-4x+7");

    ASSERT_TRUE(p.LED_P_Q() == Rational("4"));
}


// Тесты для функции DEG_P_N - степень многочлена

// №22 - нулевой многочлен

TEST(DEG_P_N_TEST, Deg_zero_pol){
    Polynomial p("0");

    ASSERT_TRUE(p.DEG_P_N() == -1);
}

// №23 - многочлен нулевой степени

TEST(DEG_P_N_TEST, Deg_zero_deg){
    Polynomial p("1334");

    ASSERT_TRUE(p.DEG_P_N() == 0);
}

// №24 - общий случай

TEST(DEG_P_N_TEST, Deg_general_case){
    Polynomial p("535x^1000-17x^543-x");

    ASSERT_TRUE(p.DEG_P_N() == 1000);
}


/*Тесты для функции FAC_P_Q - вынесение из многочелна НОК знаменателей
коэффициентов и НОД числителей*/

// №25 - нулевой многочлен

TEST(FAC_P_Q_TEST, Fac_zero_pol){
    Polynomial p("0");

    ASSERT_TRUE(p.FAC_P_Q() == Rational("0"));
}

// №26 - одночлен

TEST(FAC_P_Q_TEST, Fac_monomial){
    Polynomial p("5/2x^4");

    ASSERT_TRUE(p.FAC_P_Q() == Rational("5/2"));
}

// №27 - общий случай

TEST(FAC_P_Q_TEST, Fac_general_case){
    Polynomial p("15/2x^3+5x^2+25/4x");

    ASSERT_TRUE(p.FAC_P_Q() == Rational("5/4"));
}


// Тесты для функции MUL_PP_P - умножение многочлен

// №28 - умножение на нулевой многочлен

TEST(MUL_PP_P_TEST, Mul_zero_pol){
    Polynomial p1("0");
    Polynomial p2("x^3+2x^2+4x+1");

    p1.MUL_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("0"));
}

// №29 - умножение на многочлен нулевой степени

TEST(MUL_PP_P_TEST, Mul_zero_deg){
    Polynomial p1("5");
    Polynomial p2("10/3x^2-40/3x");

    p1.MUL_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("50/3x^2-200/3x"));
}

// №30 - возведение в квадрат

TEST(MUL_PP_P_TEST, Mul_square){
    Polynomial p1("x+1");
    Polynomial p2("x+1");

    p1.MUL_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("x^2+2x+1"));
}

// №31 - разность квадратов (фсу)

TEST(MUL_PP_P_TEST, Mul_diff_square){
    Polynomial p1("2x+5");
    Polynomial p2("2x-5");

    p1.MUL_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("4x^2-25"));
}

// №32 - общий случай

TEST(MUL_PP_P_TEST, Mul_general_case){
    Polynomial p1("x^7+x^3-2");
    Polynomial p2("x^2+22");

    p1.MUL_PP_P(p2);

    ASSERT_TRUE(p1 == Polynomial("x^9+22x^7+x^5+22x^3-2x^2-44"));
}


/*Тесты для функции DIV_PP_P - частное от деления многочлена на многочлен
при делении с остатком*/

// №33 - делимое нулевой многочлен

TEST(DIV_PP_P_TEST, Div_zero_divisible){
    Polynomial p1("0");
    Polynomial p2("x^8+17x^5");

    ASSERT_TRUE(p1.DIV_PP_P(p2) == Polynomial("0"));
}

// №34 - деление на многочлен нулевой степени с коэф. 1

TEST(DIV_PP_P_TEST, Div_one_divisor){
    Polynomial p1("x^4+13x^2-7");
    Polynomial p2("1");

    ASSERT_TRUE(p1.DIV_PP_P(p2) == Polynomial("x^4+13x^2-7"));
}

// №35 - деление на нулевой многочлен

TEST(DIV_PP_P_TEST, Div_error){
    Polynomial p1("3x^2-8/3x+1");
    Polynomial p2("0");

    ASSERT_THROW(p1.DIV_PP_P(p2), std::invalid_argument);
}

// №36 - степень делителя больше

TEST(DIV_PP_P_TEST, Div_deg_divisor_greater){
    Polynomial p1("x+1");
    Polynomial p2("x^3");

    ASSERT_TRUE(p1.DIV_PP_P(p2) == Polynomial("0"));
}

// №37 - общий случай

TEST(DIV_PP_P_TEST, Div_general_case){
    Polynomial p1("x^4-5x^3-6x^2+7x-2");
    Polynomial p2("x-1");

    ASSERT_TRUE(p1.DIV_PP_P(p2) == Polynomial("x^3-4x^2-10x-3"));
}


/*Тесты для функции MOD_PP_P - остаток от деления многочлена на многочлен
при делении с остатком*/

// №38 - степень делителя больше

TEST(MOD_PP_P_TEST, Mod_deg_devisor_greater){
    Polynomial p1("x-1");
    Polynomial p2("x^3");

    ASSERT_TRUE(p1.MOD_PP_P(p2) == Polynomial("x-1"));
}

// №39 - многочлены равны

TEST(MOD_PP_P_TEST, Mod_equal_pol){
    Polynomial p1("x^2+4");
    Polynomial p2("x^2+4");

    ASSERT_TRUE(p1.MOD_PP_P(p2) == Polynomial("0"));
}

// №40 - деление на нулевой многочлен

TEST(MOD_PP_P_TEST, Mod_error){
    Polynomial p1("3x^2-8/3x+1");
    Polynomial p2("0");

    ASSERT_THROW(p1.MOD_PP_P(p2), std::invalid_argument);
}

// №41 - общий случай

TEST(MOD_PP_P_TEST, Mod_general_case){
    Polynomial p1("x^3-12x^2-42");
    Polynomial p2("x-3");

    ASSERT_TRUE(p1.MOD_PP_P(p2) == Polynomial("-123"));
}


// Тесты для функции GCF_PP_P - НОД многочленов

// №42 - многочлены равны

TEST(GCF_PP_P_TEST, Gcf_equal_pol){
    Polynomial p1("x^2+3");
    Polynomial p2("x^2+3");

    ASSERT_TRUE(p1.GCF_PP_P(p2) == Polynomial("x^2+3"));
}

// №43 - один из многочленов нулевой

TEST(GCF_PP_P_TEST, Gcf_zero_pol){
    Polynomial p1("x^3+x-19");
    Polynomial p2("0");

    ASSERT_TRUE(p1.GCF_PP_P(p2) == Polynomial("x^3+x-19"));
}

// №44 - общий случай

TEST(GCF_PP_P_TEST, Gcf_general_case){
    Polynomial p1("x^8+x^6-3x^4-3x^3+8x^2+2x-5");
    Polynomial p2("3x^6+5x^4-4x^2-9x+21");

    ASSERT_TRUE(p1.GCF_PP_P(p2) == Polynomial("1"));
}


// Тесты для функции DEP_PP_P - производная многочлена

// №45 - нулевой многочлен

TEST(DEP_PP_P, Dep_zero_pol){
    Polynomial p("0");

    ASSERT_TRUE(p.DEP_P_P() == Polynomial("0"));
}

// №46 - многочлен нулевой степени

TEST(DEP_PP_P, Dep_zero_deg){
    Polynomial p("5");

    ASSERT_TRUE(p.DEP_P_P() == Polynomial("0"));
}

// №47 - общий случай

TEST(DEP_PP_P, Dep_general_case){
    Polynomial p("3x^4+8x^2-2x+5");

    ASSERT_TRUE(p.DEP_P_P() == Polynomial("12x^3+16x-2"));
}


/*Тесты для функции NMR_P_P - преобразование многочлена -
кратные корни в простые*/

// №48 - у многочлена только один корень и он кратный

TEST(NMR_P_P_TEST, Nmr_only_multiple_root){
    Polynomial p("x^2+2x+1");

    ASSERT_TRUE(p.NMR_P_P() == Polynomial("x+1"));
}

// №49 - у многочлена есть кратные корни и простые корни

TEST(NMR_P_P_TEST, Nmr_multiple_roots_and_not_multiple_roots){
    Polynomial p("x^4+18x^3+107x^2+220x+50");

    ASSERT_TRUE(p.NMR_P_P() == Polynomial("x^3+13x^2+42x+10"));
}

// №50 - у многочлена нет кратных корней

TEST(NMR_P_P_TEST, Nmr_no_multiple_root){
    Polynomial p("4x^3+6x^2-166x-84");

    ASSERT_TRUE(p.NMR_P_P() == Polynomial("4x^3+6x^2-166x-84"));
}


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}