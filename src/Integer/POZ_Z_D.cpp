// Created by Shegoleva Nadezhda (2382) on 31.10.2023.
// Функция определения положительности числа.
// Если число положительное, функция вернет 2.
// Если отрицательное, функция вернет 1.
// Если число является нулем, функция вернет 0.

#define CLS_EXPORTS
#include "INTEGER.h"

int Integer::POZ_Z_D() {
    if (number.NZER_N_B())
        return this->sign ? 1 : 2;
    else
        return 0;
}

