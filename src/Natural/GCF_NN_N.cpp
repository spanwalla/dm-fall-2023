//
// Created by Muravin Egor (2382) on 30.10.2023.
// НОД натуральных чисел
// 

#include "NATURAL.h"

Natural Natural::GCF_NN_N(const Natural& number) {
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
