// Created by Shegoleva Nadezda gr2382 31.10
// Функция находит абсолютную величину числа
#include "INTEGER.h"

Integer Integer::ABS_Z_Z() {
    Integer abs = *this;
    abs.sign = false;
    return abs;
}
