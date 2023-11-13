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

// №3 - числитель и знаменатель равны

TEST(REQ_Q_Q_TEST, Req_denominator_numerator_equal){
    Rational r("53452/53452");

    r.RED_Q_Q();

    ASSERT_TRUE(r == Rational("1/1"));
}

// №4 - числитель меньше знаменателя

TEST(REQ_Q_Q_TEST, Req_numerator_less_denominator){
    Rational r("4234/657542");

    r.RED_Q_Q();

    ASSERT_TRUE(r == Rational("2117/328771"));   
}

// №5 - отрицательеый числитель

TEST(REQ_Q_Q_TEST, Req_negative_numerator){
    Rational r("-54/162");

    r.RED_Q_Q();

    ASSERT_TRUE(r == Rational("-1/3"));
}

// №6 - числитель равен 0

TEST(REQ_Q_Q_TEST, Req_zero_numerator){
    Rational r("0/13242343");

    r.RED_Q_Q();

    ASSERT_TRUE(r == Rational("0/1"));
}

// №7 - общий случай

TEST(REQ_Q_Q_TEST, Req_general_case){
    Rational r("453456342646/214234353443422");

    r.RED_Q_Q();

    ASSERT_TRUE(r == Rational("226728171323/107117176721711"));
}


// Тесты для функции INT_Q_B - проверка сокращенного дробного на целое

// №8 - знаменатель 1

TEST(INT_Q_B_TEST, Int_denominator_1){
    Rational r("4223552523/1");

    ASSERT_TRUE(r.INT_Q_B());
}

// №9 - знаменатель не 1

TEST(INT_Q_B_TEST, Int_denominator_not_1){
    Rational r("52352342/8654");

    ASSERT_FALSE(r.INT_Q_B());
}


// Тесты для функции TRANS_Z_Q - преобразование целого в дробное

// №10 - положительное целое

TEST(TRANS_Z_Q_TEST, Trans_pozitive_integer){
    Rational r;
    Integer i ("54354");

    ASSERT_TRUE(r.TRANS_Z_Q(i) == Rational("54354"));
}

// №11 - отрицательное целое

TEST(TRANS_Z_Q_TEST, Trans_negative_integer){
    Rational r;
    Integer i ("-32523");

    ASSERT_TRUE(r.TRANS_Z_Q(i) == Rational("-32523"));
}

// №12 - целое равно 0

TEST(TRANS_Z_Q_TEST, Trans_zero_integer){
    Rational r;
    Integer i ("0");

    ASSERT_TRUE(r.TRANS_Z_Q(i) == Rational("0"));
}


/*Тесты для функции TRANS_Q_Z - преобрзование сокращенного дробного в
целое (если знаменатель равен 1)*/

// №13 - знаменатель равен 1, числитель положительный

TEST(TRANS_Q_Z_TEST, Trans_pozitive_rational){
    Rational r("21424234/1");

    ASSERT_TRUE(r.TRANS_Q_Z() == Integer("21424234"));
}

// №14 - знаменатель равен 1, числитель отрицательный

TEST(TRANS_Q_Z_TEST, Trans_negative_rational){
    Rational r("-132432/1");

    ASSERT_TRUE(r.TRANS_Q_Z() == Integer("-132432"));
}

// №15 - знаменатель не равен 1

TEST(TRANS_Q_Z_TEST, Trans_error){
    Rational r("123/456345");

    ASSERT_THROW(r.TRANS_Q_Z(), std::invalid_argument);
}

// №16 - число 0

TEST(TRANS_Q_Z_TEST, Trans_zero_rational){
    Rational r("0");

    ASSERT_TRUE(r.TRANS_Q_Z() == Integer("0"));
}


// Тесты для функции ADD_QQ_Q - сложение дробей

// №17 - отрицательное и положительное, положительный результат

TEST(ADD_QQ_Q_TEST, Add_neg_poz_poz){
    Rational r1 ("-32/7");
    Rational r2("40/7");

    r1.ADD_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("8/7"));
}

// №18 - отрицательное и положительное, отрицательный результат

TEST(ADD_QQ_Q_TEST, Add_neg_poz_neg){
    Rational r1 ("-19/5");
    Rational r2("13/5");

    r1.ADD_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("-6/5"));
}

// №19 - положительное и отрицательное положительный результат

TEST(ADD_QQ_Q_TEST, Add_poz_neg_poz){
    Rational r1 ("17/6");
    Rational r2("-14/6");

    r1.ADD_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("1/2"));
}

// №20 - положительное и отрицательное отрицательный результат

TEST(ADD_QQ_Q_TEST, Add_poz_neg_neg){
    Rational r1 ("53/8");
    Rational r2("-120/16");

    r1.ADD_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("-7/8"));
}

// №21 - сложение с 0

TEST(ADD_QQ_Q_TEST, Add_zero){
    Rational r1 ("2342/35");
    Rational r2("0");

    r1.ADD_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("2342/35"));
}

// №22 - сложение с рациональным без знаменателя

TEST(ADD_QQ_Q_TEST, Add_num_without_denominator){
    Rational r1 ("92/100");
    Rational r2("3");

    r1.ADD_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("98/25"));
}

// №23 - отрицательное и отрицательное

TEST(ADD_QQ_Q_TEST, Add_neg_neg){
    Rational r1 ("-123/17");
    Rational r2("-60/17");

    r1.ADD_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("-183/17"));
}

// №24 - положительное и положительное

TEST(ADD_QQ_Q_TEST, Add_poz_poz){
    Rational r1 ("6/5");
    Rational r2("17/10");

    r1.ADD_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("29/10"));
}

// №25 - сократимый результат

TEST(ADD_QQ_Q_TEST, Add_with_fraction){
    Rational r1 ("7/15");
    Rational r2("23/15");

    r1.ADD_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("2/1"));
}


// Тесты для функции SUB_QQ_Q - вычитание дробей

// №26 - отрицательное и отрицательное, отрицательный результат

TEST(SUB_QQ_Q_TEST, Sub_neg_neg_neg){
    Rational r1 ("-76/3");
    Rational r2 ("-6/3");

    r1.SUB_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("-70/3"));
}

// №27 - отрицательное и отрицательное, положительный результат

TEST(SUB_QQ_Q_TEST, Sub_neg_neg_poz){
    Rational r1 ("-3/2");
    Rational r2 ("-10/2");

    r1.SUB_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("7/2"));
}

// №28 - положительное и положительное, положительный результат

TEST(SUB_QQ_Q_TEST, Sub_poz_poz_poz){
    Rational r1 ("7/8");
    Rational r2 ("1/8");

    r1.SUB_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("3/4"));
}

// №29 - положительное и положительное отрицательный результат

TEST(SUB_QQ_Q_TEST, Sub_poz_poz_neg){
    Rational r1 ("3/4");
    Rational r2 ("10/4");

    r1.SUB_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("-7/4"));
}

// №30 - положительное и отрицательное

TEST(SUB_QQ_Q_TEST, Sub_poz_neg){
    Rational r1 ("7/4");
    Rational r2 ("-18/2");

    r1.SUB_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("43/4"));
}

// №31 - отрицательное и положительное

TEST(SUB_QQ_Q_TEST, Sub_neg_poz){
    Rational r1 ("-89/17");
    Rational r2 ("32/17");

    r1.SUB_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("-121/17"));
}

// №32 - рациональное без знаменателя

TEST(SUB_QQ_Q_TEST, Sub_num_without_denominator){
    Rational r1 ("74/10");
    Rational r2 ("5");

    r1.SUB_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("12/5"));
}

// №33 - вычитание 0

TEST(SUB_QQ_Q_TEST, Sub_zero){
    Rational r1 ("3/5");
    Rational r2 ("0");

    r1.SUB_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("3/5"));
}

// №34 - сократимый результат

TEST(SUB_QQ_Q_TEST, Sub_with_fraction){
    Rational r1 ("182/100");
    Rational r2 ("82/100");

    r1.SUB_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("1/1"));
}


// Тесты для функции MUL_QQ_Q - умножение дробей

// №35 - дроби разных знаков

TEST(MUL_QQ_Q, Mul_different_sign){
    Rational r1 ("-5/6");
    Rational r2 ("7/8");

    r1.MUL_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("-35/48"));
}

// №36 - положительные дроби

TEST(MUL_QQ_Q, Mul_poz_poz){
    Rational r1 ("7/4");
    Rational r2 ("9/20");

    r1.MUL_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("63/80"));
}

// №37 - отрицательные дроби

TEST(MUL_QQ_Q, Mul_neg_neg){
    Rational r1 ("-7/8");
    Rational r2 ("-5/45");

    r1.MUL_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("7/72"));
}

// №38 - умножение на 0

TEST(MUL_QQ_Q, Mul_zero){
    Rational r1 ("57387/4234");
    Rational r2 ("0");

    r1.MUL_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("0/1"));
}

// №39 - умножение на 1

TEST(MUL_QQ_Q, Mul_one){
    Rational r1 ("3453/46");
    Rational r2 ("1");

    r1.MUL_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("3453/46"));
}

// №40 - умножение на -1

TEST(MUL_QQ_Q, Mul_neg_one){
    Rational r1 ("2346/42");
    Rational r2 ("-1");

    r1.MUL_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("-391/7"));
}

// №41 - общий случай

TEST(MUL_QQ_Q, Mul_general_case){
    Rational r1 ("36553545346/6456");
    Rational r2 ("235345346/7657545");

    r1.MUL_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("2150676694245264929/12359277630"));
}


// Тесты для функции DIV_QQ_Q - деление дробей

// №42 - деление на 0

TEST(DIV_QQ_Q_TEST, Div_error){
    Rational r1("34/6");
    Rational r2("0");

    ASSERT_THROW(r1.DIV_QQ_Q(r2), std::logic_error);
}

// №43 - числа равны

TEST(DIV_QQ_Q_TEST, Div_equal_nums){
    Rational r1("7/5");
    Rational r2("7/5");

    r1.DIV_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("1/1"));
}

// №44 - несократимый результат

TEST(DIV_QQ_Q_TEST, Div_not_fraction_result){
    Rational r1("4/5");
    Rational r2("7/9");

    r1.DIV_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("36/35"));
}

// №45 - сократимый результат

TEST(DIV_QQ_Q_TEST, Div_fraction_result){
    Rational r1("2/3");
    Rational r2("4/9");

    r1.DIV_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("3/2"));
}

// №46 - одно из чисел отрицательное

TEST(DIV_QQ_Q_TEST, Div_neg_poz){
    Rational r1("-3/5");
    Rational r2("7/9");

    r1.DIV_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("-27/35"));
}

// №47 - делимое 1

TEST(DIV_QQ_Q_TEST, Div_divisible_one){
    Rational r1("1");
    Rational r2("67/98");

    r1.DIV_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("98/67"));
}

// №48 - делитель 1

TEST(DIV_QQ_Q_TEST, Div_divisor_one){
    Rational r1("73/6");
    Rational r2("1");

    r1.DIV_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("73/6"));
}

// №49 - делитель -1

TEST(DIV_QQ_Q_TEST, Div_divisor_neg_one){
    Rational r1("6/8");
    Rational r2("-1");

    r1.DIV_QQ_Q(r2);

    ASSERT_TRUE(r1 == Rational("-3/4"));
}


// Тесты для функции INV_Q_Q - обратная дробь

// №50 - 0 в числителе

TEST(INV_Q_Q, Inv_zero_numerator){
    Rational r("0/10");

    ASSERT_TRUE(r.INV_Q_Q() == Rational("0"));
}

// №51 - положительная дробь

TEST(INV_Q_Q, Inv_poz_numerator){
    Rational r("5/2");

    ASSERT_TRUE(r.INV_Q_Q() == Rational("2/5"));
}

// №52 - отрицательная дробь

TEST(INV_Q_Q, Inv_neg_numerator){
    Rational r("-7/8");

    ASSERT_TRUE(r.INV_Q_Q() == Rational("-8/7"));
}

// №53 - сократимая дробь

TEST(INV_Q_Q, Inv_fraction){
    Rational r("18/8");

    ASSERT_TRUE(r.INV_Q_Q() == Rational("4/9"));
}

// №54 - несократимая дробь

TEST(INV_Q_Q, Inv_not_fraction){
    Rational r("19/11");

    ASSERT_TRUE(r.INV_Q_Q() == Rational("11/19"));
}


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
