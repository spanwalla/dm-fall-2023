// Created by Dmitriy Chepasov (2382) on 29.10.2023.
// Прибавление единицы к натуральному числу (инкремент).

#define CLS_EXPORTS
#include "NATURAL.h"

void Natural::ADD_1N_N() {
    std::size_t ind = 0;
    short sum = 0;
    if (this->digits[ind] + 1 == 10) {
        while (ind < this->digits.size()) {
            sum = short(this->digits[ind] + 1);
            if (sum == 10) {
                sum %= 10;
                this->digits[ind] = sum;
                ind++;
            } else {
                this->digits[ind] = sum;
                break;
            }
        }
        if (ind == this->digits.size()) this->digits.push_back(1);
    }
    else
        this->digits[ind]++;
}
