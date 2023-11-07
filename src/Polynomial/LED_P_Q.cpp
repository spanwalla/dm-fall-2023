// Created by Dmitry Chepasov (2382) on 07.11.2023.
// Старший коэффициент многочлена.

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

Rational Polynomial::LED_P_Q() {
    this->clean_zero();
    return this->coefficients.back();
}
