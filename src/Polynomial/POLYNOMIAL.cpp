//
// Created by Mihail Fedorov (2382) on 31.10.2023.
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

Polynomial::Polynomial(std::vector<Rational> coefficients): coefficients(coefficients) {}

Polynomial::Polynomial() : Polynomial({Rational(0)}) {}

std::ostream& operator << (std::ostream& out, const Polynomial& polynomial) {
    bool flag_zero = true;
    for (size_t i = polynomial.coefficients.size() - 1; i != -1; --i) {
        if (!polynomial.coefficients[i].is_zero()) {
            flag_zero = false;
            if (i != polynomial.coefficients.size() - 1)
                out << (polynomial.coefficients[i].is_sign() ? "" : "+");
            out << polynomial.coefficients[i];
            if (i > 0) {
                out << (i == 1 ? "x" : "x^" + std::to_string(i));
            }
        }
    }
    if (flag_zero)
        out << 0;
    return out;
}
