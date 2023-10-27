#ifndef polinom_cpp
#define polinom_cpp

#include "polinom.h"

Polinom::Polinom(const std::string const_polinom_str) {
    std::string polinom_str(const_polinom_str.substr(const_polinom_str[0] == '+' ? 1 : 0));

    unsigned long long index_right = 0;
    while (polinom_str.size()) {

        index_right = polinom_str.find('x');
        RatFraction tmp_value(polinom_str.substr(0, index_right));
        polinom_str = polinom_str.substr(index_right + 2);

        for (index_right = 0; index_right < polinom_str.size() && '0' <= polinom_str[index_right] && polinom_str[index_right] <= '9'; ++index_right);
        unsigned long long tmp_key = std::stoi(polinom_str.substr(0, index_right));
        this->pol[tmp_key] = std::move(tmp_value);

        polinom_str = index_right == polinom_str.size() ? "" : polinom_str.substr(index_right + 1);
    }
}

std::string Polinom::str_polinom() const {
    std::string str_polinom = "";
    for (auto const& pair : this->pol)
        str_polinom += (pair.second.str_frac()[0] == '-' ? "" : "+") + pair.second.str_frac() + "x^" + std::to_string(pair.first);
    return str_polinom;
}

#endif