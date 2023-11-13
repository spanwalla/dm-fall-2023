//
// Created by Leonid Ivashinnikov (2382) on 12.11.2023.
// Найти обратную дробь. Поменять местами числитель и знаменатель.
//

#define CLS_EXPORTS
#include "RATIONAL.h"

Rational Rational::INV_Q_Q() const {
    if (this->is_zero())
        return Rational("0");
    Rational inverted = Rational(Integer::TRANS_N_Z(this->denominator), this->numerator.ABS_Z_Z().TRANS_Z_N());
    if (this->is_sign())
        inverted.numerator.MUL_ZM_Z();
    inverted.RED_Q_Q();
    return inverted;
}
