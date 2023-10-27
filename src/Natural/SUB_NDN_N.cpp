//
// Created by Muravin Egor (2382) on 27.10.2023.
// Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом.
// Умножаем число на некий коэф.
// Используем SUB_NN_N чтобы найди абсолютную разницу
//
#include "NATURAL.h"

// SUB_NDN_N считает n1 - n2*k >= 0
void Natural::SUB_NDN_N(Natural &number, short digit)
{
    Natural temp = number;
    temp.MUL_ND_N(digit);
    SUB_NN_N(temp);
}



