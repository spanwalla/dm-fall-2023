// Created by Bukharin Maxim (2382) on 01.11.2023.
// Преобразование целого в дробное
// Был написан конструктор, принимающий целое

#include "RATIONAL.h"

Rational Rational::TRANS_Z_Q(const Integer& number) {
    return Rational(number);
}