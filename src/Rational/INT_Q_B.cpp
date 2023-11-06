// Created by Bukharin Maxim (2382) on 04.11.2023.
// Проверка сокращённого дробного числа на целое.

#define CLS_EXPORTS
#include "RATIONAL.h"

bool Rational::INT_Q_B() const {
    return this->denominator.COM_NN_D(Natural(1)) == 0; // возвращаем, равен ли знаменатель единице
}
