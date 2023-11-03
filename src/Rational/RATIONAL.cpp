//
// Created by Mihail Fedorov (2382) on 31.10.2023.
//

#define CLS_EXPORTS
#include "RATIONAL.h"

Rational::Rational(const std::string& number) {
    if (number.find('/') == std::string::npos)
        this->denominator = Natural("1");
    else
        this->denominator = Natural(number.substr(number.find('/') + 1));
    this->numerator = Integer(number.substr(0, number.find('/')));
    if (!this->denominator.NZER_N_B())
        throw std::invalid_argument("The denominator cannot be zero.");
}

Rational::Rational() : numerator("0"), denominator("1") {}

bool Rational::is_zero() const { return this->numerator.POZ_Z_D() == 0; }

bool Rational::is_sign() const { return this->numerator.POZ_Z_D() == 1; }

std::ostream& operator << (std::ostream& out, const Rational& number) {
    out << number.numerator << "/" << number.denominator;
    return out;
}