//
// Created by Egor Muravin (2382) on 30.10.2023.
// НОД натуральных чисел.
// 

#define CLS_EXPORTS
#include "NATURAL.h"

Natural Natural::GCF_NN_N(const Natural& number) const {
    if (!NZER_N_B() && !number.NZER_N_B()) // проверка, два числа не ноль
        throw std::logic_error("One of the numbers must have non-zero value.");
    Natural temp_one = *this; // записываем в буфер первое число
    Natural temp_two = number; // записываем в буфер второе число
    while (temp_one.NZER_N_B() && temp_two.NZER_N_B()) { // цикла пока первое и второе число не ноль
        if (temp_one.COM_NN_D(temp_two) == 2) // если первое больше второго
            temp_one = temp_one.MOD_NN_N(temp_two); // записываем на место первого числа его остаток от деления на второе число
        else // если второе число больше второго
            temp_two = temp_two.MOD_NN_N(temp_one); // записываем на место второго числа его остаток от деления на первое число
    }
    temp_one.ADD_NN_N(temp_two); //складываем первое и второе число
    return temp_one;
}
