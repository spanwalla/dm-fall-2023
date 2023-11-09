// Created by Aleksandr Kochurov (2382) on 05.11.2023.
// Умножение дробей.

#define CLS_EXPORTS
#include "RATIONAL.h"

void Rational::MUL_QQ_Q(const Rational &number) {
    this->numerator.MUL_ZZ_Z(number.numerator);
    this->denominator.MUL_NN_N(number.denominator);
    this->RED_Q_Q(); // сокращаем дробь
}
