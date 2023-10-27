//
// Created by Leonid Ivashinnikov (2382) on 25.10.2023.
// Конструкторы класса и оператор вывода в поток.
// Создание объекта из строки и целого числа long long int.
// Значение по умолчанию: 0. В векторе числа хранятся в обратном порядке!!! В нулевом индексе хранится самый младший разряд.
//

#include "NATURAL.h"

Natural::Natural(const std::string& number) {
    for (auto c : std::ranges::reverse_view(number)) {
        if (!std::isdigit(c))
            throw std::invalid_argument("Natural number expects a sequence of digits.");
        this->digits.push_back(short(c - '0'));
    }
    if (digits.empty())
        this->digits.push_back(0);
}

Natural::Natural() {
    this->digits = {0};
}

std::ostream& operator << (std::ostream& out, const Natural& number) {
    for (short digit : std::ranges::reverse_view(number.digits))
        out << digit;
    return out;
}

Natural::Natural(long long int num) {
    if (num < 0)
        throw std::invalid_argument("Number must be greater than or equal to 0.");

    while (num > 0) {
        this->digits.push_back(short(num % 10));
        num /= 10;
    }

    if (digits.empty())
        this->digits.push_back(0);
}
std::vector <short> Natural::get_digit(){
    return this->digits;
}
int Natural::COM_NN_D(Natural& cmp){
        std::vector <short> vcmp = cmp.get_digit();
        if(vcmp.size() == this->digits.size()){
            for (int i = vcmp.size()-1;i>=0;i++){
                if(vcmp[i] != this->digits[i]){
                    if(vcmp[i]>this->digits[i]){
                        return 1;
                    }
                    if(vcmp[i] <this->digits[i]){
                        return 2;
                    }
                    }
                }
                return 0;
            }
        return (this->digits.size() > vcmp.size() ? 2 : 1);

}
