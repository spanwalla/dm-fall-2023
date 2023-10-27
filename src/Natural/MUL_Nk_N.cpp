#include "NATURAL.h"
//Created by Chepasov Dmitry(2382)
//Умножает на 10^k
void Natural:: MUL_Nk_N(unsigned long long int k){

    if (digits[digits.end()] != 0)
        digits.insert(digits.begin(), k, 0);
    else {
        digits.erase();
        digits.push_back(0);
    }
}
