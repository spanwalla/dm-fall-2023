//
// Created by Leonid Ivashinnikov (2382) on 25.10.2023.
// Проверка на ноль: если число не равно нулю, то "да", иначе "нет".
// Проходимся по массиву, если откуда-то там появилось несколько нулей.
// Если встретили не ноль, возвращаем true. Если ничего не встретили, false.
//

#include "NATURAL.h"

bool Natural::NZER_N_B() const {
    for (auto i: this->digits)
        if (i != 0)
            return true;

    return false;
}