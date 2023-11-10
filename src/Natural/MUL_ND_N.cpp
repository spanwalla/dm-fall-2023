// Created by Sofya Bodareva (2382) on 27.10.2023.
// Умножение натурального числа на цифру,
// для чисел больших 1 логика как для умножения в столбик.

#define CLS_EXPORTS
#include "NATURAL.h"

void Natural::MUL_ND_N(short digit){
    int carry = 0;
    int tmp = 0;
    if (digit == 0)
            this->digits = {0};
    else if (digit > 1 && digit < 10) {
        for (int i {0}; i < this->digits.size(); ++i) {
            tmp = (this->digits[i] * digit) + carry;
            this->digits[i] = tmp % 10;
            carry = tmp / 10;
        }
        if (carry != 0) {
            this->digits.push_back(carry);
        }
    }
}

