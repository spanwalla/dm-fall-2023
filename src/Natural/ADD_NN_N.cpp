// Created by Dmitry Chepasov (2382) on 28.10.2023.
// Сложение натуральных чисел.

#define CLS_EXPORTS
#include "NATURAL.h"

void Natural::ADD_NN_N(const Natural& number) {
    Natural addable_number = number;
    
    short carry = 0;
    std::size_t index = 0;

    while (this->digits.size() < addable_number.digits.size())
        this->digits.push_back(0);
    while (addable_number.digits.size() < this->digits.size())
        addable_number.digits.push_back(0);
    
    while (index < this->digits.size()) {
        auto digit_sum = this->digits[index] + addable_number.digits[index] + carry;
        carry = short(digit_sum / 10);
        if (digit_sum >= 10)
            digit_sum %= 10;

        this->digits[index] = short(digit_sum);
        index++;
    }
    
    if(carry != 0)
        this->digits.push_back(carry);
}
