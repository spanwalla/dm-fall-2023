// Created by Shegoleva Nadezhda (2382) on 31.10.2023.
// Функция находит абсолютную величину числа.

#define CLS_EXPORTS
#include "INTEGER.h"

Integer Integer::ABS_Z_Z() {
    Integer abs = *this;
    abs.sign = false;
    return abs;
}
