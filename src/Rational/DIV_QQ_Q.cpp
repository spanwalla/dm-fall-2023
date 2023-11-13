// Created by Aleksandr Kochurov (2382) on 05.11.2023.
// Деление дробей (делитель отличен от нуля).

#define CLS_EXPORTS
#include "RATIONAL.h"

void Rational::DIV_QQ_Q(const Rational &number) {
    if(number.numerator.POZ_Z_D() == 0) // Проверка деления на ноль.
        throw std::logic_error("Division by zero.");

    this->MUL_QQ_Q(number.INV_Q_Q()); // Умножаем дробь на обратную.
}
