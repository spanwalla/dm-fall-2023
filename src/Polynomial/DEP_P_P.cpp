// Created by Bukharin Maxim (2382) on 09.11.2023.
// Производная от многочлена

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

void Polynomial::DEP_P_P() {
    size_t i;
    for (i = 1; i < this->coefficients.size(); ++i) { // цикл, проходящий по всем индексам вектора коэффицентов многочлена
        this->coefficients.at(i).MUL_QQ_Q(Rational(std::to_string(i))); // умножаем текущий коэффицент на значение позиции в векторе, т.е. на степень
    }
    this->coefficients.erase(this->coefficients.begin()); // удаляем элемент с 0 степенью
}