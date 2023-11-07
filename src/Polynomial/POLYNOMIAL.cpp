//
// Created by Mihail Fedorov (2382) on 31.10.2023.
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

#include <utility>

Polynomial::Polynomial(std::vector<Rational> coefficients): coefficients(std::move(coefficients)) {
    this->clean_zero();
}

Polynomial::Polynomial() : Polynomial({Rational()}) {}

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

void Polynomial::clean_zero() {
    while (coefficients.size() > 1 && coefficients.back().is_zero())
        coefficients.pop_back();
}

bool Polynomial::is_zero() {
    return std::ranges::all_of(coefficients.cbegin(), coefficients.cend(), [](auto i) { return i.is_zero(); });
}
