// Created by Dmitry Chepasov (2382) on 27.10.2023.
// Сравнение двух натуральных чисел.

#define CLS_EXPORTS
#include "NATURAL.h"

int Natural::COM_NN_D(const Natural& cmp) const {
        if (cmp.digits.size() == this->digits.size()) {
            for (int i = digits.size() - 1; i >= 0; --i) {
                if (cmp.digits[i] != this->digits[i])
                    return (this->digits[i] > cmp.digits[i] ? 2 : 1);
            }
            return 0;
        }
        return (this->digits.size() > cmp.digits.size() ? 2 : 1);
}
