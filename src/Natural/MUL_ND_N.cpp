// Created by Sofya Bodareva (2382) on 27.10.2023.
// Умножение натурального числа на цифру,
// для чисел больших 1 логика как для умножения в столбик.

#define CLS_EXPORTS
#include "NATURAL.h"

void Natural::MUL_ND_N(short digit){
    int carry = 0; // переменная для хранения смещения
    int tmp = 0;
    if (digit == 0)
            this->digits = {0}; // проверка цифры на 0
    else if (digit > 1 && digit < 10) {
        for (int i {0}; i < this->digits.size(); ++i) {
            tmp = (this->digits[i] * digit) + carry; // умножаем текущую цифру числа на нужную и прибавляем смещение с прошлого шага
            this->digits[i] = tmp % 10; // оставляем в текущей ячейке последнюю цифру произведения
            carry = tmp / 10; // учитываем смещение
        }
        if (carry != 0) {
            this->digits.push_back(carry); // учитываем случай, когда в числе появляется новая цифра
        }
    }
}

