#include "NATURAL.h"

void Natural::ADD_1N_N(){
    size_t ind = 0;
    int summ = 0;
    if(this->digits[ind] + 1 == 10){
    while(ind<this->digits.size()){
        summ = this->digits[ind] + 1;
        if (summ ==10){
            summ %=10;
            this->digits[ind] = summ;
            ind ++;
        }
        else{
            this->digits[ind] = summ;
            break;
        }
    }
     if(ind == this->digits.size()) this->digits.push_back(1);
    }
    else this->digits[ind] ++;
}
