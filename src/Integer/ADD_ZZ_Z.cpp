// Created by Nadezhda Shegoleva (2382) on 02.11.2023.
// Функция складывает два целых числа.

#define CLS_EXPORTS
#include "INTEGER.h"

void Integer::ADD_ZZ_Z(Integer b) {
    if (this->POZ_Z_D() == b.POZ_Z_D()) // this->sign == b.sign
        this->number.ADD_NN_N(b.number);
    else {
        if (this->number.COM_NN_D(b.number) == 2)
            this->number.SUB_NN_N(b.number);

        else {
            this->sign = b.sign;
            b.number.SUB_NN_N(this->number);
            this->number = b.number;
        }
    }
}
