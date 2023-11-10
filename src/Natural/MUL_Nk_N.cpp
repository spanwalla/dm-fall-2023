// Created by Dmitry Chepasov (2382) on 27.10.2023.
// Умножение на 10^k.

#define CLS_EXPORTS
#include "NATURAL.h"

void Natural::MUL_Nk_N(unsigned long long int k) {
    if (this->digits[digits.size()-1] != 0)
        this->digits.insert(digits.begin(), k, 0);
    else {
        this->digits.clear();
        this->digits.push_back(0);
    }
}
