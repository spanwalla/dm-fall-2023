// Created by Semenenko Anna 02.11.2023
// Частное от деления целого на целое (делитель отличен от нуля)

#define CLS_EXPORTS
#include "INTEGER.h"

Integer Integer::DIV_ZZ_Z(Integer& divisor){
    if (!divisor.number.NZER_N_B())
        throw std::logic_error("The divisor must not be zero!");
    Natural nat = this->number.DIV_NN_N(divisor.number);
    Integer quotient(nat);
    quotient.sign = !(this->sign == divisor.sign || this->POZ_Z_D() == 0);
    // добавляем единицу по модулю если делимое - отрицательное с остатком от деления отличным от нуля
    if (this->sign == 1 && this->number.MOD_NN_N(divisor.number).NZER_N_B())
        quotient.number.ADD_1N_N();
    return quotient;
}
