//
// Created by Mihail Fedorov (2382) on 31.10.2023.
//

#define CLS_EXPORTS
#include "POLINOM.h"

// получаемая строка выглядист так a(n)x^n+a(n-1)x^n-1+...+a(0) или a(n)*x^n+a(n-1)*x^n-1+...+a(0)
// вместо плюсов могут стоять минусы
Polinom::Polinom(const std::string& content) {
    std::string pol(content);

    std::vector<std::string> substr_pol;
    size_t size = 0;

    while (!pol.empty()) {
        size_t index_sub = std::min(pol.find('-', 1), pol.find('+', 1));
        substr_pol.push_back(pol.substr(0, index_sub));

        size_t index_degree = pol.find('^');
        if (index_degree == std::string::npos && pol.find('x') != std::string::npos)
            size = std::max(size, (size_t)1);
        else
            size = std::max(size, (size_t)std::stoi(pol.substr(pol.find('^') + 1, index_sub)));
        
        if (index_sub == std::string::npos)
            pol = "";
        else
            pol = pol.substr(index_sub);
    }

    std::vector<Rational> coef_polinom(size + 1, Rational());
    for (auto singelton : substr_pol) {
        size_t index_sub_left = std::min(singelton.find('x'), singelton.find('*'));
        size_t index_sub_right = singelton.find('^');

        if (index_sub_left == std::string::npos)
            index_sub_left = singelton.size();

        if (index_sub_right != std::string::npos)
            coef_polinom[std::stoi(singelton.substr(index_sub_right + 1, singelton.size()))] = Rational(singelton.substr(0, index_sub_left));
        else if (singelton.find('x') == std::string::npos)
            coef_polinom[0] = Rational(singelton.substr(0, index_sub_left));
        else
            coef_polinom[1] = Rational(singelton.substr(0, index_sub_left));

        // std::cout << std::stoi(singelton.substr(index_sub_right + 1, singelton.size())) << "=" << singelton.substr(0, index_sub_left) << std::endl;
    }
    this->coef_polinom = std::move(coef_polinom);
}

Polinom::Polinom() { this->coef_polinom.push_back(Rational()); }

std::ostream& operator << (std::ostream& out, const Polinom& polinom) {
    for (size_t i = polinom.coef_polinom.size() - 1; i != -1; --i) {
        if (!polinom.coef_polinom[i].is_zero()) {
            if (i != polinom.coef_polinom.size() - 1)
                out << (polinom.coef_polinom[i].is_sign() ? "" : "+");
            out << polinom.coef_polinom[i];
            if (i > 0) {
                out << (i == 1 ? "x" : "x^" + std::to_string(i));
            }
        }
    }
    return out;
}