//
// Created by Egor Muravin (2382) on 30.10.2023.
// НОК натуральных чисел.
// 

#define CLS_EXPORTS
#include "NATURAL.h"

Natural Natural::LCM_NN_N(const Natural& number) const {
    Natural temp_one = *this; // записываем в буфер первое число
    const Natural& temp_two = number; // записываем в буфер второе число
    Natural nod = temp_one.GCF_NN_N(temp_two); // находим НОД двух чисел
    temp_one.MUL_NN_N(temp_two); // умножаем первое число на второе число
    return temp_one.DIV_NN_N(nod); // делим произведение двух чисел на их НОД
}
