//
// Created by Muravin Egor (2382) on 26.10.2023.
// Вычитание из первого большего натурального числа второго меньше или равного
// С помощью COM_NN_D определяем какое число больше
// Затем из большего вычитаем меньшее
//
#ifndef SUB_NN_N_cpp
#define SUB_NN_N_cpp
#include "NATURAL.h"


short Natural::COM_NN_D(Natural &number) const
{
    if (len() == number.len())
    {
        for (int i = len() - 1; i >= 0; i--)
        {
            if (digits[i] > number[i])
                return 2;
            if (digits[i] < number[i])
                return 1;
        }
        return 0;
    }
    else if (len() > number.len())
        return 2;
    return 1;
}

/* int carry = 0;
    if (COM_NN_D(number) == 0)
    {
        digits = {0};
    }
    else if (COM_NN_D(number) == 2)
    {
        number.zfill(len() - number.len()); // выравниваю длину нулями
        for (int i = 0; i < len(); i++)
        {
            short difference = digits[i] - number[i] - carry;
            if (difference < 0)
            {
                difference += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            digits[i] = difference;
        }
    }
    else
    {
        throw std::logic_error("A natural number cannot be negative!");
    }
    clean_zero();
    number.clean_zero(); */





Natural Natural::SUB_NN_N(Natural &number)
{
    
    Natural temp;
    int carry = 0;
    if (COM_NN_D(number) == 2)
    {
        temp = *this;
        number.zfill(len() - number.len()); // выравниваю длину нулями
        for (int i = 0; i < len(); i++)
        {
            short difference = temp[i] - number[i] - carry;
            carry = difference < 0 ? 1 : 0;
            difference = difference < 0 ? difference += 10 : difference;
            temp[i] = difference;
        }
    }
    else
    {
        temp = number;
        zfill(temp.len() - len()); // выравниваю длину нулями
        for (int i = 0; i < len(); i++)
        {
            short difference = temp[i] - digits[i] - carry;
            carry = difference < 0 ? 1 : 0;
            difference = difference < 0 ? difference += 10 : difference;
            temp[i] = difference;
        }
    }
    clean_zero();
    temp.clean_zero();
    return temp;
}

#endif