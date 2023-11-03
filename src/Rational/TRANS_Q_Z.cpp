// Created by Bukharin Maxim (2382) on 01.11.2023.
// Преобразование дробного в целое (если знаменатель равен 0)

#include "RATIONAL.h"

Integer Rational::TRANS_Q_Z() {
    if (!this->INT_Q_B())
        throw std::invalid_argument("The denominator must be 1.");
    return this->numerator;
}