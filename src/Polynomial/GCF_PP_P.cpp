//
// Created by Leonid Ivashinnikov (2382) on 12.11.2023.
// НОД многочленов. Алгоритм такой же, как и для натуральных чисел.
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

Polynomial Polynomial::GCF_PP_P(const Polynomial& polynomial) const {
    Polynomial dividend = *this; // делимое
    Polynomial divisor = polynomial; // делитель
    Rational multiplier;
    while (dividend.DEG_P_N() != -1 && divisor.DEG_P_N() != -1) {
        Polynomial tmp = divisor;
        divisor = dividend.MOD_PP_P(divisor);
        dividend = tmp;
    }
    Polynomial result = divisor.DEG_P_N() > dividend.DEG_P_N() ? divisor : dividend;
    result.clean_zero();
    multiplier = result.FAC_P_Q();
    if (result.LED_P_Q().is_sign()) // Поменяем знаки у многочлена, если старший коэффициент отрицательный.
        multiplier.MUL_QQ_Q(Rational("-1"));
    result.MUL_PQ_P(multiplier.INV_Q_Q());
    return result;
}