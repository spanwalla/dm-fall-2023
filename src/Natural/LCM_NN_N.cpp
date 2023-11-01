//
// Created by Muravin Egor (2382) on 30.10.2023.
// НОК натуральных чисел
// 

#define CLS_EXPORTS
#include "NATURAL.h"

Natural Natural::LCM_NN_N(const Natural& number) {
    Natural temp_one = *this;
    const Natural& temp_two = number;
    Natural nod = temp_one.GCF_NN_N(temp_two);
    temp_one.MUL_NN_N(temp_two);
    return temp_one.DIV_NN_N(nod);
}
