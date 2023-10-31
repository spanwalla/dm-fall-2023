//
// Created by Mihail Fedorov (2382) on 31.10.2023.
//

#include "RATIONAL.h"

Rational::Rational(const std::string& number) {
    if (number.find('/') == std::string::npos)
        throw std::invalid_argument("Characted '/' not found.");
    this->numerator = Integer(number.substr(0, number.find('/')));
    this->denominator = Natural(number.substr(number.find('/') + 1));
    if (!this->denominator.ABS_Z_N().NZER_N_B())
        throw std::invalid_argument("The denominator cannot be zero.");
}

Rational::Rational() : numerator("0"), denominator("1") {}

std::ostream& operator << (std::ostream& out, const Rational& number) { out << number.numerator << "/" << number.denominator; }
