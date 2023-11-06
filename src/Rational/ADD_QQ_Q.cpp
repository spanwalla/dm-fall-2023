// Created by Aleksandr Kochurov (2382) on 05.11.2023.
// Сложение дробей.


#define CLS_EXPORTS
#include "RATIONAL.h"

void Rational::ADD_QQ_Q(const Rational &number) {
    Integer this_denominator(this->denominator);// знаменатель 1 дроби
    Integer number_denominator(number.denominator); // знаменатель 2 дроби
    Integer buf_numerator(number.numerator); // числитель 2 дроби
    buf_numerator.MUL_ZZ_Z(this_denominator); // умножаем числитель 2 дроби на знаменатель 1 дроби
    this->numerator.MUL_ZZ_Z(number_denominator);
    this->numerator.ADD_ZZ_Z(buf_numerator); // складываем числители
    this->denominator.MUL_NN_N(number.denominator); // умножаем знаменатели
    this->RED_Q_Q(); // сокращаем дробь
}
