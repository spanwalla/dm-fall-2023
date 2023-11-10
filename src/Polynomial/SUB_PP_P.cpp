//
// Created by Mihail Fedorov (2382) on 11.11.2023.
// вычитание многочленов
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

void Polynomial::SUB_PP_P(const Polynomial& other) {
    for (size_t i = 0; i < other.coefficients.size(); ++i) {
        if (i >= this->coefficients.size())
            this->coefficients.push_back(Rational("0"));
        this->coefficients[i].SUB_QQ_Q(other.coefficients[i]);
    }
}