//
// Created by Egor Muravin (2382) on 27.10.2023.
// Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом.
// Умножаем число на некий коэффициент.
// Используем SUB_NN_N, чтобы найти абсолютную разницу.
//

#define CLS_EXPORTS
#include "NATURAL.h"

// SUB_NDN_N считает n1 - n2*k >= 0
void Natural::SUB_NDN_N(const Natural &number, short digit) {
    Natural temp = number; // записываем в буфер входное число, чтобы случайно не изменить его
    temp.MUL_ND_N(digit); //умножаем на входное число на входную переменную  digit
    SUB_NN_N(temp); // находим разность чисел
}



