//
// Created by Mihail Fedorov (2382) on 11.11.2023.
// Деление с целой частью.
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

Polynomial Polynomial::DIV_PP_P(const Polynomial& divisor) const {
    if (divisor.is_zero())
        throw std::invalid_argument("Division by zero");
    
    Polynomial quotient("0");
    Polynomial remainder(*this);

    int deg_dividend = remainder.DEG_P_N();
    int deg_divisor = divisor.DEG_P_N();

    while (deg_dividend >= deg_divisor) {
        Rational coeff = remainder.LED_P_Q();
        Rational tmp_coeff = divisor.LED_P_Q();
        coeff.DIV_QQ_Q(tmp_coeff);

        int degree_difference = deg_dividend - deg_divisor;

        std::vector<Rational> temp(degree_difference + 1, Rational("0"));
        temp[degree_difference] = coeff;

        Polynomial temp_polynomial(temp);
        quotient.ADD_PP_P(temp_polynomial);

        Polynomial product = divisor;
        product.MUL_Pxk_P(degree_difference);
        product.MUL_PQ_P(coeff);

        remainder.SUB_PP_P(product);

        deg_dividend = remainder.DEG_P_N();
    }

    return std::move(quotient);
}
