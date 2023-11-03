// Created by Bukharin Maxim (2382) on 01.11.2023.
// Проверка на целое

#include "RATIONAL.h"

bool Rational::INT_Q_B() {
    return this->denominator.COM_NN_D(Natural("1")) == 0;
}