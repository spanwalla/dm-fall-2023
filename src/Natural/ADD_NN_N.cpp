//Create by Chepasov Dmitry (gr 2382) 28.10.23
 #include "NATURAL.h"
void Natural::ADD_NN_N(Natural& addable_number){
unsigned carry = 0;
size_t index_this =0;
size_t index_addable =0;
if (this->digits.size() < addable_number.digits.size()) std::swap(this->digits,addable_number.digits); //Меняем их, так как сложение будет происходить в столбоик правильно, если число большее сверху
while(index_this < this->digits.size() || index_addable < addable_number.digits.size()){
    auto digitsum = this->digits[index_this] + addable_number.digits[index_addable] + carry;

    carry = digitsum / 10;
    digitsum %= 10;

    this->digits[index_this] = digitsum;
    index_this++;
    index_addable++;
    }
    if(carry != 0)
      this->digits.push_back(carry);
}
