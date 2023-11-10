// Created by Bukharin Maxim (2382) on 09.11.2023.
// Производная от многочлена

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

Polynomial Polynomial::DEP_P_P() const {
    std::vector<Rational> new_coefficients(this->DEG_P_N() > 0 ? this->DEG_P_N : 1, Rational("0")); // коэффиценты производного многочлена
    size_t i;
    for (i = 1; i < this->DEG_P_N(); ++i) { // цикл, проходящий по всем индексам вектора коэффицентов многочлена
        new_coefficients[i - 1] = this->coefficients[i];
        new_coefficients[i - 1].MUL_QQ_Q(Rational(std::to_string(i))); // умножаем текущий коэффицент на значение позиции в векторе, т.е. на степень
    }

    return Polynomial(new_coefficients);
}
