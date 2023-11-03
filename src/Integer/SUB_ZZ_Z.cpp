// Created by Shegoleva Nadezhda (2382) on 02.11.2023.
// Функция вычитает одно целое число из другого

#define CLS_EXPORTS
#include "INTEGER.h"

void Integer::SUB_ZZ_Z(Integer b){
    if (this->sign == b.sign){
        if (this->number.COM_NN_D(b.number) != 1) { // a>=b
            this->number.SUB_NN_N(b.number);
        }
        else{
            this->sign = !b.sign;
            b.number.SUB_NN_N(this->number);
            this->number = b.number;
        }
    }
    else{
        this->number.ADD_NN_N(b.number);
    }
}
