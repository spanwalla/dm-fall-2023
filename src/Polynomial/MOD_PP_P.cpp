//
// Created by Mihail Fedorov (2382) on 11.11.2023.
// Остаток от деления двух многочленов.
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

Polynomial Polynomial::MOD_PP_P(const Polynomial& divisor) const {
    if (divisor.is_zero()) {
        throw std::invalid_argument("Division by zero");
    }
    
    Polynomial remainder(*this);

    int deg_dividend = remainder.DEG_P_N();
    int deg_divisor = divisor.DEG_P_N();

    while (deg_dividend >= deg_divisor) {
        Rational coeff = remainder.LED_P_Q();
        Rational tmp_coeff = divisor.LED_P_Q();
        coeff.DIV_QQ_Q(tmp_coeff);

        int degree_difference = deg_dividend - deg_divisor;

        Polynomial product = divisor;
        product.MUL_Pxk_P(degree_difference);
        product.MUL_PQ_P(coeff);

        remainder.SUB_PP_P(product);

        deg_dividend = remainder.DEG_P_N();
    }

    return std::move(remainder);
}
