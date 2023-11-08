// Created by Kochurov Aleksandr (2382) on 07.11.2023.
// Сложение многочленов


#define CLS_EXPORTS
#include "POLYNOMIAL.h"

void Polynomial::ADD_PP_P(const Polynomial &polynomial) {
    size_t i;
    for (i = 0; i < this->coefficients.size() && i < polynomial.coefficients.size(); ++i) { // цикл проходящий от 0 до конца this, либо  до конца polynomial в зависимости от размеров
        this->coefficients[i].ADD_QQ_Q(polynomial.coefficients[i]);
    }
    for (;i < polynomial.coefficients.size(); ++i){ // на случай если polynomial оказался больше чем this
        this->coefficients.push_back(polynomial.coefficients[i]);
    }
    this->clean_zero();
}
