//
// Created by Mihail Fedorov (2382) on 31.10.2023.
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

#include <utility>

Polynomial::Polynomial(const std::string& content) {
    std::string pol(content);

    std::vector<std::string> substr_pol;
    size_t size = 0;

    while (!pol.empty()) {
        size_t index_sub = std::min(pol.find('-', 1), pol.find('+', 1));
        substr_pol.push_back(pol.substr(0, index_sub));

        size_t index_degree = pol.find('^');
        if (index_degree == std::string::npos && pol.find('x') != std::string::npos)
            size = std::max(size, (size_t)1);
        else if (pol.find('^') != std::string::npos)
            size = std::max(size, (size_t)std::stoi(pol.substr(pol.find('^') + 1, index_sub)));
        
        if (index_sub == std::string::npos)
            pol = "";
        else
            pol = pol.substr(index_sub);
    }

    std::vector<Rational> coefficients(size + 1, Rational());
    for (auto singelton : substr_pol) {
        size_t index_sub_left = std::min(singelton.find('x'), singelton.find('*'));
        size_t index_sub_right = singelton.find('^');

        if (index_sub_left == std::string::npos)
            index_sub_left = singelton.size();

        if (index_sub_right != std::string::npos)
            coefficients[std::stoi(singelton.substr(index_sub_right + 1, singelton.size()))] += Rational(singelton.substr(0, index_sub_left));
        else if (singelton.find('x') == std::string::npos)
            coefficients[0] += Rational(singelton.substr(0, index_sub_left));
        else
            coefficients[1] += Rational(singelton.substr(0, index_sub_left));

    }
    this->coefficients = std::move(coefficients);
    this->clean_zero();
}

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
