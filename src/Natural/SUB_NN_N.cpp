//
// Created by Muravin Egor (2382) on 26.10.2023.
// Вычитание из первого большего натурального числа второго меньше или равного
// С помощью COM_NN_D определяем какое число больше
// Затем из большего вычитаем меньшее
//
#ifndef SUB_NN_N_cpp
#define SUB_NN_N_cpp
#include "NATURAL.h"

// КОД ДИМЫ
/* short Natural::COM_NN_D(Natural &number) const
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
} */




Natural Natural::SUB_NN_N(Natural &number)
{
    Natural temp;
    if (COM_NN_D(number) == 2)
    {
        temp = *this;
        temp -= number;
    }
    else
    {
        temp = number;
        temp -= *this;
    }
    return temp;
}

#endif