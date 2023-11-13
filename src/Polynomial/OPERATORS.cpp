//
// Created by Mihail Fedorov (2382) on 13.11.2023.
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

bool operator==(const Polynomial& first, const Polynomial& second) {
    if (first.coefficients.size() != second.coefficients.size())
        return false;
    for (size_t i = 0; i < first.coefficients.size(); ++i)
        if (first.coefficients[i] != second.coefficients[i])
            return false;
    return true;
}

bool operator!=(const Polynomial& first, const Polynomial& second) { return !(first == second); }

Polynomial operator+(const Polynomial& first, const Polynomial& second) {
    Polynomial new_polynom(first);
    new_polynom.ADD_PP_P(second);
    return std::move(new_polynom);
}

Polynomial operator-(const Polynomial& first, const Polynomial& second) {
    Polynomial new_polynom(first);
    new_polynom.SUB_PP_P(second);
    return std::move(new_polynom);
}

Polynomial operator*(const Polynomial& first, const Polynomial& second) {
    Polynomial new_polynom(first);
    new_polynom.MUL_PP_P(second);
    return std::move(new_polynom);
}

Polynomial operator/(const Polynomial& first, const Polynomial& second) { return std::move(first.DIV_PP_P(second)); }

Polynomial operator%(const Polynomial& first, const Polynomial& second) { return std::move(first.MOD_PP_P(second)); }

Polynomial& Polynomial::operator+=(const Polynomial& other) {
    this->ADD_PP_P(other);
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
    this->SUB_PP_P(other);
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
    this->MUL_PP_P(other);
    return *this;
}

Polynomial& Polynomial::operator/=(const Polynomial& other) {
    *this = this->DIV_PP_P(other);
    return *this;
}

Polynomial& Polynomial::operator%=(const Polynomial& other) {
    *this = this->MOD_PP_P(other);
    return *this;
}
