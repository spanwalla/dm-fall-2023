// Created by Maxim Bukharin (2382) on 09.11.2023.
// Производная от многочлена.

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

Polynomial Polynomial::DEP_P_P() const {
    std::vector<Rational> new_coefficients(this->DEG_P_N() > 0 ? this->DEG_P_N() : 1); // Коэффициенты производного многочлена.
    for (int i = 1; i <= this->DEG_P_N(); ++i) { // Цикл, проходящий по всем индексам вектора коэффициентов многочлена.
        new_coefficients[i - 1] = this->coefficients[i];
        new_coefficients[i - 1].MUL_QQ_Q(Rational(std::to_string(i))); // Умножаем текущий коэффициент на значение позиции в векторе, т.е. на степень.
    }
    return Polynomial(new_coefficients);
}
