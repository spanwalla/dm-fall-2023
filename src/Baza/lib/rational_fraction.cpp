#ifndef rational_fraction_cpp
#define rational_fraction_cpp

#include "rational_fraction.h"
#include <stdexcept>
#include <algorithm>
#include <regex>

bool RatFraction::is_rational_fraction(std::string num) {
    std::regex pattern("-?[0-9][0-9]*/[1-9][0-9]*");
    return std::regex_match(num, pattern);
}

void RatFraction::swap(RatFraction& other) {
    std::swap(this->numer, other.numer);
    std::swap(this->denomin, other.denomin);
}

RatFraction::RatFraction() {}

RatFraction::RatFraction(const std::string const_frac_str) {
    if (!this->is_rational_fraction(const_frac_str))
        throw std::invalid_argument("Object RatFraction exept a rational fraction."); 

    std::string frac_str(const_frac_str);

    unsigned long long index_tok = frac_str.find('/');

    Num tmp_n(frac_str.substr(0, index_tok));
    this->numer = std::move(tmp_n);
    UNum tmp_d(frac_str.substr(index_tok + 1));
    this->denomin = std::move(tmp_d);

}

RatFraction::RatFraction(const RatFraction& other) : numer(other.numer), denomin(other.denomin) {}

RatFraction::RatFraction(RatFraction&& other) : RatFraction() { this->swap(other); }

RatFraction& RatFraction::operator=(const RatFraction& other) {
    if (this == &other)
        return *this;
    
    RatFraction tmp(other);
    this->swap(tmp);
    return *this;
}

RatFraction& RatFraction::operator=(RatFraction&& other) {
    if (this == &other)
        return *this;

    this->swap(other);
    return *this;
}

std::string RatFraction::str_frac() const { return this->numer.str_num() + "/" + this->denomin.str_num(); }

#endif