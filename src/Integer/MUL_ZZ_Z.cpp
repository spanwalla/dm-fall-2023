// Created by Anna Semenenko (2382) on 01.11.2023.
// Умножение целых чисел.

#define CLS_EXPORTS
#include "INTEGER.h"

void Integer::MUL_ZZ_Z(const Integer& num) {
    this->number.MUL_NN_N(num.number);
    this->sign = !(this->sign == num.sign || this->POZ_Z_D() == 0 || num.POZ_Z_D() == 0);
}
