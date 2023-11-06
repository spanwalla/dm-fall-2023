// Created by Maxim Bukharin (2382) on 04.11.2023.
// Преобразование дробного в целое (если знаменатель равен 1).
// Код может быть переделан с использованием RED_Q_Q, когда будет написан этот метод.

#define CLS_EXPORTS
#include "RATIONAL.h"

Integer Rational::TRANS_Q_Z() const {
    if (!this->INT_Q_B())
        throw std::invalid_argument("The denominator must be 1.");
    return this->numerator; // возвращаем числитель
}
