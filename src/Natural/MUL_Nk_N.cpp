// Created by Chepasov Dmitry (2382) 27.10.2023
// Умножает на 10^k

#include "NATURAL.h"

void Natural:: MUL_Nk_N(unsigned long long int k) {
    if (this->digits[digits.size()-1] != 0)
        this->digits.insert(digits.begin(), k, 0);
    else {
        this->digits.clear();
        this->digits.push_back(0);
    }
}
