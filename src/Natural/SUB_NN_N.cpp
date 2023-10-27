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
    Natural temp = number;
    int carry = 0;
    if (COM_NN_D(number) == 1)
        throw std::logic_error("The first number must be less than the second");
    temp.zfill(len() - temp.len()); // заполняет нулями с конца
    for (int i = 0; i < len(); i++)
    {
        short difference = digits[i] - temp.digits[i] - carry;
        carry = difference < 0 ? 1 : 0;
        difference = difference < 0 ? difference += 10 : difference;
        digits[i] = difference;
    }
    clean_zero(); // очищает нули в начале
    temp.clean_zero();
    return *this;
}

#endif
