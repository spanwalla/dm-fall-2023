//
// Created by Leonid Ivashinnikov (2382) on 25.10.2023.
// Проверка на ноль: если число не равно нулю, то "да", иначе "нет".
// Используем функцию any_of из ranges (аналог any() в Python).
// Если встретили не ноль, возвращаем true. Если ничего не встретили, false.
//

#define CLS_EXPORTS
#include "NATURAL.h"

bool Natural::NZER_N_B() const {
    return std::ranges::any_of(digits.crbegin(), digits.crend(), [](auto i) { return i != 0; });
}