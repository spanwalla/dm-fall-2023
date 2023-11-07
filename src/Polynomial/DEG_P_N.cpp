//
// Created by Leonid Ivashinnikov (2382) on 07.11.2023.
// Степень многочлена. По сути, индекс последнего ненулевого элемента в массиве.
// Степень многочлена, тождественно равного нулю, не определена, но в некоторых случаях её принимают равной −1.
// Степень константы, не равной нулю, — 0. Пример: 4
// Степень линейного многочлена — 1. Пример: 2x
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

int Polynomial::DEG_P_N() const {
    int last_index = -1;
    for (auto it = coefficients.rbegin(); it != coefficients.rend(); ++it) { // Проходимся с конца массива
        if (!it->is_zero()) { // Встретили ненулевой элемент
            last_index = int(coefficients.rend() - it - 1); // Определение индекса на основе итератора
            break;
        }
    }
    return last_index; // Если не нашли, то многочлен тождественен нулю, его степень не определена, но мы считаем -1.
}