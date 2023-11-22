//
// Created by Mihail Fedorov (2382) on 11.11.2023.
// Деление с целой частью.
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

Polynomial Polynomial::DIV_PP_P(const Polynomial& divisor) const {
    // проверяем на деление на нуль
    if (divisor.is_zero())
        throw std::invalid_argument("Division by zero");

    // создаём целую часть и остаток
    Polynomial quotient("0");
    Polynomial remainder(*this);

    // сохраняем в переменные степени многочленом
    int deg_dividend = remainder.DEG_P_N();
    int deg_divisor = divisor.DEG_P_N();

    // пока делимое можно поделить, делим
    while (deg_dividend >= deg_divisor) {
        // находим коэффициент, на который нужно умножить делитель
        Rational coeff = remainder.LED_P_Q();
        Rational tmp_coeff = divisor.LED_P_Q();
        coeff.DIV_QQ_Q(tmp_coeff);

        // находим степень одночлена, на который нужно умножить делитель
        int degree_difference = deg_dividend - deg_divisor;

        // создаем одночлен
        std::vector<Rational> temp(degree_difference + 1, Rational("0"));
        temp[degree_difference] = coeff;

        Polynomial temp_polynomial(temp);
        //обновляем целое частное
        quotient.ADD_PP_P(temp_polynomial);

        // находим полином, который нужно вычесть из делимого, что уменьшить его степень
        Polynomial product = divisor;
        product.MUL_Pxk_P(degree_difference);
        product.MUL_PQ_P(coeff);

        remainder.SUB_PP_P(product);

        // обновляем переменную степени
        deg_dividend = remainder.DEG_P_N();
    }

    // возвращаем получившийся многочлен
    return std::move(quotient);
}
