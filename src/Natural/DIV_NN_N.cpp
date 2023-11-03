// Created by Sofya Bodareva (2382) on 28.10.2023
// Поиск неполного частного двух натуральных чисел

#define CLS_EXPORTS
#include "NATURAL.h"

Natural Natural::DIV_NN_N(const Natural& number) const {
    if (this->COM_NN_D(number) == 0) // если числа равны, их неполное частное равно 1
        return Natural(1);
    else if (this->COM_NN_D(number) == 1) // если делимое меньше делителя, их неполное частное 0
        return Natural(0);
    else if (number.COM_NN_D(Natural(1)) == 0) // если делитель равен 1, неполное частное равно this
        return *this;
    else {
        Natural res;
        Natural tmp1 = *this;
        Natural tmp2;
        while (tmp1.COM_NN_D(number) == 2) {
            tmp2 = tmp1.DIV_NN_Dk(number); // находим первую цифру частного * 10^k (k - позиция)
            res.ADD_NN_N(tmp2); // прибавляем промежуточный результат к общему
            tmp2.MUL_NN_N(number);             
            tmp1.SUB_NN_N(tmp2);
        }
        return res;
    }
}
