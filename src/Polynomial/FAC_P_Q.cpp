// Created by Mihail Fedorov (2382) on 11.11.2023.
// Вынесение из многочлена НОД числителей и НОК знаменателей.

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

Rational Polynomial::FAC_P_Q() const {
    Natural numerator = LED_P_Q().get_numerator().ABS_Z_Z().TRANS_Z_N();
    Natural denominator = LED_P_Q().get_denominator();

    for (size_t i = 0; i < this->coefficients.size() - 1; ++i) {
        numerator = numerator.GCF_NN_N(this->coefficients[i].get_numerator().ABS_Z_Z().TRANS_Z_N());
        denominator = denominator.LCM_NN_N(this->coefficients[i].get_denominator());
    }

    return {Integer::TRANS_N_Z(numerator), denominator};
}
