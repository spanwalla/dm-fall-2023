//
// Created by Mihail Fedorov (2382) on 11.11.2023.
// Вычитание многочленов.
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

void Polynomial::SUB_PP_P(const Polynomial& other) {
    if (!other.is_zero()) {
        for (int i = 0; i <= other.DEG_P_N(); ++i) {
            if (i > this->DEG_P_N())
                this->coefficients.emplace_back("0");
            this->coefficients[i].SUB_QQ_Q(other.coefficients[i]);
        }
    }
    this->clean_zero();
}

