// Сreated by Sofya Bodareva (2382) on 29.10.2023.
// Умножение двух натуральных чисел.

#define CLS_EXPORTS
#include "NATURAL.h"

void Natural::MUL_NN_N(Natural number) {
    if (!this->NZER_N_B() || !number.NZER_N_B()) { // проверка обоих чисел на 0
        this->digits = {0};
    } else if (this->COM_NN_D(Natural(1)) == 0) { // проверка первого множителя на 1
        this->digits = number.digits;
    } else {
        Natural res;
        Natural tmp;
        if (this->COM_NN_D(number) == 1)
            std::swap(*this, number); // меняем местами this и number, если this < number

        for (int i {0}; i < number.digits.size(); ++i) {
            tmp.digits = this->digits;
            tmp.MUL_ND_N(number.digits[i]); // умножение на цифру из number
            tmp.MUL_Nk_N(i); // учет смещения на i разрядов
            res.ADD_NN_N(tmp);
        }
        this->digits = res.digits;
    }
}
