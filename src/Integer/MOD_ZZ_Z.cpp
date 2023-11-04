// Created by Anna Semenenko (2382) on 02.11.2023.
// Остаток от деления целого на целое (делитель отличен от нуля).

#define CLS_EXPORTS
#include "INTEGER.h"

Integer Integer::MOD_ZZ_Z(const Integer &num) const {
    Natural nat = this->number.MOD_NN_N(num.number);
    Integer remainder(nat);
    // Если делимое отрицательное и остаток отличен от нуля, то остаток равен (делитель - остаток).
    if (this->sign && remainder.number.NZER_N_B()) {
        // (остаток минус делитель) по модулю
        remainder.SUB_ZZ_Z(num.ABS_Z_Z());
        remainder.sign = false;
    }
    return remainder;
}