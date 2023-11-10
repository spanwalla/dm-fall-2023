//
// Created by Leonid Ivashinnikov (2382) on 10.11.2023.
// Умножение многочленов. Алгоритм взят из учебника по дискретной математике С.В. Рыбина.
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

void Polynomial::MUL_PP_P(Polynomial polynomial) {
    if (!polynomial.is_zero()) {
        // Определим многочлен большей степени и будем считать, что многочлен большей степени находится в нашем объекте.
        if (polynomial.DEG_P_N() > DEG_P_N())
            std::swap(this->coefficients, polynomial.coefficients);

        int first_degree = DEG_P_N();
        int second_degree = polynomial.DEG_P_N();

        std::vector<Rational> result(first_degree + second_degree + 1, Rational("0"));

        for (int k = 0; k <= second_degree; ++k) {
            for (int j = 0; j <= k; ++j) {
                Rational multiply_result(coefficients[j]);
                multiply_result.MUL_QQ_Q(polynomial.coefficients[k-j]);
                result[k].ADD_QQ_Q(multiply_result);
            }
        }

        for (int k = second_degree + 1; k <= first_degree; ++k) {
            for (int j = k - second_degree; j <= k; ++j) {
                Rational multiply_result(coefficients[j]);
                multiply_result.MUL_QQ_Q(polynomial.coefficients[k-j]);
                result[k].ADD_QQ_Q(multiply_result);
            }
        }

        for (int k = first_degree + 1; k <= first_degree + second_degree; ++k) {
            for (int j = k - second_degree; j <= first_degree; ++j) {
                Rational multiply_result(coefficients[j]);
                multiply_result.MUL_QQ_Q(polynomial.coefficients[k-j]);
                result[k].ADD_QQ_Q(multiply_result);
            }
        }

        this->coefficients = result;
        clean_zero();
    } else {
        this->coefficients.clear();
        this->coefficients.emplace_back("0");
    }
}
