// Created by Shegoleva Nadezhda (2382) on 31.10.2023.
// Функция умножает целое число на -1

#define CLS_EXPORTS
#include "INTEGER.h"

void Integer::MUL_ZM_Z() {
    if (number.NZER_N_B())
        this->sign = !this->sign;
}
