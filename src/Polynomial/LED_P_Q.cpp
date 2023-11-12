// Created by Dmitry Chepasov (2382) on 07.11.2023.
// Старший коэффициент многочлена.

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

Rational Polynomial::LED_P_Q() const {
    for (auto & coefficient : std::ranges::reverse_view(coefficients)) { // Проходимся с конца массива
        if (!coefficient.is_zero()) // Встретили ненулевой элемент
            return coefficient;
    }
    return Rational("0");
}
