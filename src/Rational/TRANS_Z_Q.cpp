// Created by Maxim Bukharin (2382) on 04.11.2023.
// Преобразование целого в дробное.
// Был написан конструктор, принимающий целое.

#define CLS_EXPORTS
#include "RATIONAL.h"

Rational Rational::TRANS_Z_Q(const Integer& number) {
    return Rational(number);
}