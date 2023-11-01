// Created by Semenenko Anna 01.11.2023
// Умножение целых чисел

#define CLS_EXPORTS
#include "INTEGER.h"

void Integer::MUL_ZZ_Z(Integer num){
    this->number.MUL_NN_N(num.number);
    (this->sign == num.sign || this->POZ_Z_D() == 0 || num.POZ_Z_D() == 0) ? this->sign = 0 : this->sign = 1;
}
