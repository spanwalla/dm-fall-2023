// Created by Fedorov Mihail (2382) on 07.11.2023.
// Перегрузка операторов для работы с дробями

#define CLS_EXPORTS
#include "RATIONAL.h"

Rational Rational::operator+(const Rational& other) const {
    Rational new_rational(other);
    new_rational.ADD_QQ_Q(*this);
    return std::move(new_rational);
}

Rational Rational::operator-() const {
    Rational new_rational(*this);
    new_rational.numerator.MUL_ZM_Z();
    return std::move(new_rational);
}

Rational Rational::operator-(const Rational& other) const {
    Rational new_rational(other);
    return *this + (-new_rational);
}

Rational Rational::operator*(const Rational& other) const {
    Rational new_rational(other);
    new_rational.MUL_QQ_Q(*this);
    return std::move(new_rational);
}

Rational Rational::operator/(const Rational& other) const {
    Rational new_rational(other);
    new_rational.DIV_QQ_Q(*this);
    return std::move(new_rational);
}

Rational& Rational::operator+=(const Rational& other) {
    *this = *this + other;
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    *this = *this - other;
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    *this = *this * other;
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    *this = *this / other;
    return *this;
}

bool Rational::operator>(const Rational& other) const {
    if (this->numerator.POZ_Z_D() != other.numerator.POZ_Z_D()) {
        if (this->numerator.POZ_Z_D() == 2 && other.numerator.POZ_Z_D() != 2)
            return true;
        if (this->numerator.POZ_Z_D() == 0 && other.numerator.POZ_Z_D() == 1)
            return true;
        return false;
    }

    Natural this_val(this->numerator.ABS_Z_Z().TRANS_Z_N());
    Natural other_val(other.numerator.ABS_Z_Z().TRANS_Z_N());
    this_val.MUL_NN_N(other.denominator);
    other_val.MUL_NN_N(this->denominator);
    return this_val.COM_NN_D(other_val) == 2;
}

bool Rational::operator<(const Rational& other) const {
    if (this->numerator.POZ_Z_D() != other.numerator.POZ_Z_D()) {
        if (this->numerator.POZ_Z_D() == 1 && other.numerator.POZ_Z_D() != 1)
            return true;
        if (this->numerator.POZ_Z_D() == 0 && other.numerator.POZ_Z_D() == 2)
            return true;
        return false;
    }

    Natural this_val(this->numerator.ABS_Z_Z().TRANS_Z_N());
    Natural other_val(other.numerator.ABS_Z_Z().TRANS_Z_N());
    this_val.MUL_NN_N(other.denominator);
    other_val.MUL_NN_N(this->denominator);
    return this_val.COM_NN_D(other_val) == 1;
}

bool Rational::operator>=(const Rational& other) const { return !(*this < other); }

bool Rational::operator<=(const Rational& other) const { return !(*this > other); }

bool Rational::operator==(const Rational& other) const {
    if (this->numerator.POZ_Z_D() != other.numerator.POZ_Z_D())
        return false;
    
    if (this->denominator.COM_NN_D(other.denominator)) 
        return false;
    
    if (this->numerator.ABS_Z_Z().TRANS_Z_N().COM_NN_D(other.numerator.ABS_Z_Z().TRANS_Z_N())) 
        return false;
    
    return true;
}

bool Rational::operator!=(const Rational& other) const { return !(*this == other); }
