//Create by Chepasov Dmitry (GR 2382) 28.10.23
#include "NATURAL.h"
void Natural::ADD_NN_N(Natural& addable_number){
    std::transform (addable_number.digits.begin(), addable_number.digits.end(),this->digits.begin(), this->digits.begin(),std::plus<int>());
}
