//
// Created by Leonid Ivashinnikov (2382) on 07.11.2023.
// Умножение многочлена на рациональное число. Пройтись по циклу и умножить каждый коэффициент.
// Особые случаи: умножение на 0 (можем сразу создать пустой массив), умножение на 1 (ничего не делать).
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

void Polynomial::MUL_PQ_P(const Rational &number) {
    if (number.is_zero() || this->is_zero()) { // Что-то равно нулю.
        this->coefficients.clear(); // Очистим коэффициенты.
        this->coefficients.emplace_back("0");
    } else { // Можем добавить сравнение number с единицей.
        for (auto & coefficient : coefficients)
            coefficient.MUL_QQ_Q(number); // Сокращение результата отрабатывается в MUL_QQ_Q.
    }
}