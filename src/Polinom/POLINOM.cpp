//
// Created by Mihail Fedorov (2382) on 31.10.2023.
//

#include "POLINOM.h"

// получаемая строка выглядист так n:+a(n)x^n+a(n-1)x^n-1+...+a(0)
// вместо плюсов могут стоять минусы
Polinom::Polinom(const std::string& content) {
    std::string pol(content);
    if (pol.find(':') == std::string::npos)
        throw std::invalid_argument("Characted ':' not found.");

    size_t size = std::stoi(pol.substr(0, pol.find(':')));
    pol = pol.substr(pol.find(':') + 1);
    std::vector<Rational> polinom(size, Rational());
    while (!pol.empty()) {
        std::string rat_num = pol.substr(0, pol.find('x'));
        pol = pol.substr(pol.find('x') + 1);
        size_t index = std::stoi(pol.substr(0, std::min(pol.find('-'), pol.find('+'))));
        pol = pol.substr(std::min(pol.find('-'), pol.find('+')) + 1);
        polinom[index] = Rational(rat_num);
    }
    this->polinom = std::move(polinom);
}

Polinom::Polinom() { this->polinom.push_back(Rational()); }

std::ostream& operator << (std::ostream& out, const Polinom& polinom) {
    out << polinom.polinom.size() << ':';
    for (size_t i = polinom.polinom.size() - 1; i != -1; ++i) {
        if (!polinom.polinom[i].is_zero())
            out << polinom.polinom[i].is_sign() ? "" : "+" << polinom.polinom[i];
    }
    return out;
}