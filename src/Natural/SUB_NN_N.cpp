//
// Created by Muravin Egor (2382) on 26.10.2023.
// Вычитание из первого большего натурального числа второго меньше или равного
// С помощью COM_NN_D определяем какое число больше
// Затем из большего вычитаем меньшее
//
#ifndef SUB_NN_N_cpp
#define SUB_NN_N_cpp
#include "NATURAL.h"

Natural Natural::SUB_NN_N(const Natural &number)
{
    Natural temp_one;
    Natural temp_two;
    int carry = 0;
    if (COM_NN_D(number) == 2)
    {
        temp_one = *this;
        temp_two = number;
    }
    else
    {
        temp_one = number;
        temp_two = *this;
    }
    temp_two.zfill(temp_one.len() - temp_two.len()); // заполняет нулями с конца
    for (int i = 0; i < temp_one.len(); i++)
    {
        short difference = temp_one.digits[i] - temp_two.digits[i] - carry;
        carry = difference < 0 ? 1 : 0;
        difference = difference < 0 ? difference += 10 : difference;
        temp_one.digits[i] = difference;
    }
    temp_one.clean_zero(); // очищает нули в начале
    temp_two.clean_zero();
    return temp_one;
}

#endif
