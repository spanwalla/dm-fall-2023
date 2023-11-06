//
// Created by Leonid Ivashinnikov (2382) on 07.11.2023.
// Умножение многочлена на x^k, по сути вставка k нулей в начало.
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

void Polynomial::MUL_Pxk_P(unsigned long long int k) {
    if (!this->is_zero()) {
        this->coefficients.insert(coefficients.begin(), k, Rational("0"));
    }
}