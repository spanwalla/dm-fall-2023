// Created by Chepasov Dmitry (gr 2382) 28.10.2023

#include "NATURAL.h"

void Natural::ADD_NN_N(const Natural& number) {
    Natural addable_number = number;
    
    unsigned carry = 0;
    size_t index = 0;

    while (this->digits.size() < addable_number.digits.size())
        this->digits.push_back(0);
    while (addable_number.digits.size() < this->digits.size())
        addable_number.digits.push_back(0);
    
    while (index < this->digits.size()) {
        auto digitsum = this->digits[index] + addable_number.digits[index] + carry;
        carry = digitsum / 10;
        if (digitsum >= 10)
            digitsum %= 10;

        this->digits[index] = digitsum;
        index++;
    }
    
    if(carry != 0)
        this->digits.push_back(carry);
}
