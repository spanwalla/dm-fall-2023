// Created by Anna Semenenko (2382) on 02.11.2023.
// Частное от деления целого на целое (делитель отличен от нуля).

#define CLS_EXPORTS
#include "INTEGER.h"

Integer Integer::DIV_ZZ_Z(const Integer& divisor) const {
    if (!divisor.number.NZER_N_B())
        throw std::logic_error("The divisor must not be zero!");
    Natural nat = this->number.DIV_NN_N(divisor.number);  // nat это натуральное частное от деления
    Integer quotient(nat);  // quotient это целое частное от деления
    quotient.sign = !(this->sign == divisor.sign || this->POZ_Z_D() == 0);  // определяем знак у целого числа
    // добавляем единицу по модулю, если делимое - отрицательное с остатком от деления, отличным от нуля
    if (this->sign == 1 && this->number.MOD_NN_N(divisor.number).NZER_N_B())
        quotient.number.ADD_1N_N();
    return quotient;
}
