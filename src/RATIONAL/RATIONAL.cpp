//
// Created by Mihail Fedorov (2382) on 31.10.2023.
//

#include "RATIONAL.h"

Rational::Rational(const std::string& number) {
    if (number.find('/') == std::string::npos)
        throw std::invalid_argument("Characted '/' not found.");
    this->numerator = Integer(number.substr(0, number.find('/')));
    this->denominator = Natural(number.substr(number.find('/') + 1));
    if (!this->denominator.NZER_N_B())
        throw std::invalid_argument("The denominator cannot be zero.");
}

Rational::Rational() : numerator("0"), denominator("1") {}

bool Rational::is_zero() const { return this->numerator.ABS_Z_N().COM_NN_D(Natural("0")) == 0; }

bool Rational::is_sign() const { return this->numerator.POZ_Z_D() == 1; }

std::ostream& operator << (std::ostream& out, const Rational& number) {
    out << number.numerator << "/" << number.denominator;
    return out;
}
