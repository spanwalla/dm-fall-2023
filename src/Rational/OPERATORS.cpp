// Created by Mihail Fedorov (2382) on 07.11.2023.
// Перегрузка операторов для работы с дробями.

#define CLS_EXPORTS
#include "RATIONAL.h"

Rational operator+(const Rational& num1, const Rational& num2) {
    Rational new_rational(num2);
    new_rational.ADD_QQ_Q(num1);
    return std::move(new_rational);
}

Rational operator-(const Rational& num) {
    Rational new_rational(num);
    new_rational.numerator.MUL_ZM_Z();
    return std::move(new_rational);
}

Rational operator-(const Rational& num1, const Rational& num2) { return num1 + (-num2); }

Rational operator*(const Rational& num1, const Rational& num2) {
    Rational new_rational(num2);
    new_rational.MUL_QQ_Q(num1);
    return std::move(new_rational);
}

Rational operator/(const Rational& num1, const Rational& num2) {
    Rational new_rational(num1);
    new_rational.DIV_QQ_Q(num2);
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

bool operator>(const Rational& num1, const Rational& num2) {
    if (num1.numerator.POZ_Z_D() != num2.numerator.POZ_Z_D()) {
        if (num1.numerator.POZ_Z_D() == 2 && num2.numerator.POZ_Z_D() != 2)
            return true;
        if (num1.numerator.POZ_Z_D() == 0 && num2.numerator.POZ_Z_D() == 1)
            return true;
        return false;
    }

    Natural this_val(num1.numerator.ABS_Z_Z().TRANS_Z_N());
    Natural other_val(num2.numerator.ABS_Z_Z().TRANS_Z_N());
    this_val.MUL_NN_N(num2.denominator);
    other_val.MUL_NN_N(num1.denominator);
    return this_val.COM_NN_D(other_val) == 2;
}

bool operator<(const Rational& num1, const Rational& num2) {
    if (num1.numerator.POZ_Z_D() != num2.numerator.POZ_Z_D()) {
        if (num1.numerator.POZ_Z_D() == 1 && num2.numerator.POZ_Z_D() != 1)
            return true;
        if (num1.numerator.POZ_Z_D() == 0 && num2.numerator.POZ_Z_D() == 2)
            return true;
        return false;
    }

    Natural this_val(num1.numerator.ABS_Z_Z().TRANS_Z_N());
    Natural other_val(num2.numerator.ABS_Z_Z().TRANS_Z_N());
    this_val.MUL_NN_N(num2.denominator);
    other_val.MUL_NN_N(num1.denominator);
    return this_val.COM_NN_D(other_val) == 1;
}

bool operator>=(const Rational& num1, const Rational& num2) { return !(num1 < num2); }

bool operator<=(const Rational& num1, const Rational& num2) { return !(num1 > num2); }

bool operator==(const Rational& num1, const Rational& num2) {
    if (num1.numerator.POZ_Z_D() != num2.numerator.POZ_Z_D())
        return false;
    
    if (num1.denominator.COM_NN_D(num2.denominator)) 
        return false;
    
    if (num1.numerator.ABS_Z_Z().TRANS_Z_N().COM_NN_D(num2.numerator.ABS_Z_Z().TRANS_Z_N())) 
        return false;
    
    return true;
}

bool operator!=(const Rational& num1, const Rational& num2) { return !(num1 == num2); }
