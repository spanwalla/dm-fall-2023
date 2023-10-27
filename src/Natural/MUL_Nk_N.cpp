#include "NATURAL.h"
//Created by Chepasov Dmitry(2382)
//Умножает на 10^k
void Natural:: MUL_Nk_N(unsigned long long int k){
    digits.insert(digits.begin(), k, 0);
}
