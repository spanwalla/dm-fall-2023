//
// Created by Muravin Egor (2382) on 30.10.2023.
// НОД натуральных чисел
// 

#define CLS_EXPORTS
#include "NATURAL.h"

Natural Natural::GCF_NN_N(const Natural& number) const {
    if (!NZER_N_B() && !number.NZER_N_B())
        throw std::logic_error("One of the numbers must have non-zero value.");
    Natural temp_one = *this;
    Natural temp_two = number;
    while (temp_one.NZER_N_B() && temp_two.NZER_N_B()) {
        if (temp_one.COM_NN_D(temp_two) == 2)
            temp_one = temp_one.MOD_NN_N(temp_two);
        else
            temp_two = temp_two.MOD_NN_N(temp_one);
    }
    temp_one.ADD_NN_N(temp_two);
    return temp_one;
}
