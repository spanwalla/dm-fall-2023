// Created by Dmitry Chepasov (2382) on 11.11.2023.
// Старший коэффициент многочлена.

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

Rational Polynomial::FAC_P_Q() const {
    Natural numerator = this->coefficients[0].get_numerator().ABS_Z_Z().TRANS_Z_N();
    Natural denominator = this->coefficients[0].get_denominator();

    for (size_t i = 1; i < this->coefficients.size(); ++i) {
        numerator = std::move(numerator.GCF_NN_N(this->coefficients[i].get_numerator().ABS_Z_Z().TRANS_Z_N()));
        denominator = std::move(denominator.LCM_NN_N(this->coefficients[i].get_denominator()));
    }

    return Rational(Integer::TRANS_N_Z(numerator), denominator);
}
