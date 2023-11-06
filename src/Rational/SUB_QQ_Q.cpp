// Created by Kochurov Aleksandr (2382) on 05.11.2023.
// вычитание дробей.


#define CLS_EXPORTS
#include "RATIONAL.h"

void Rational::SUB_QQ_Q(const Rational &number) {
    Rational buffer(number.numerator); // временная переменная для хранения number
    buffer.denominator = number.denominator;// добавляем знаменатель
    buffer.numerator.MUL_ZM_Z(); // умножаем числитель на -1
    this->ADD_QQ_Q(buffer); // складываем дроби
}
