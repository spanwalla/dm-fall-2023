// Created by Kochurov Aleksandr (2382) on 05.11.2023.
// Деление дробей (делитель отличен от нуля)


#define CLS_EXPORTS
#include "RATIONAL.h"

void Rational::DIV_QQ_Q(const Rational &number) {
    Rational buffer(Integer(number.denominator)); // временная переменная для хранения number
    if (number.numerator.POZ_Z_D() == 1){ // учитываем знак
        buffer.numerator.MUL_ZM_Z();
    }
    buffer.denominator = number.numerator.ABS_Z_Z().TRANS_Z_N();// добавляем знаменатель
    this->MUL_QQ_Q(buffer); // умножаем дроби
}
