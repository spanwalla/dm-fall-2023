// Created by Sofya Bodareva (2382) on 30.10.2023
// Остаток от деления первого натурального числа на второе

#define CLS_EXPORTS
#include "NATURAL.h"

Natural Natural::MOD_NN_N(const Natural& number) const {
    if (!number.NZER_N_B())
        throw std::logic_error("The number must not be zero!");
    
    if (COM_NN_D(number) == 0 || !NZER_N_B() || number.COM_NN_D(Natural(1)) == 0) // случаи, когда остаток равен 0
        return Natural(0);
    else if (COM_NN_D(number) == 1) // если делимое меньше делителя, остаток равен делимому
        return *this;
    else if (COM_NN_D(Natural(1)) == 0) // если делимое равно 1, остаток всегда 1
        return Natural(1);
    else {
        Natural tmp1 = *this;
        Natural tmp2 = tmp1.DIV_NN_N(number); // вычисляем неполное частное
        tmp2.MUL_NN_N(number);
        tmp1.SUB_NN_N(tmp2); // считаем остаток
        return tmp1;
    }
}

