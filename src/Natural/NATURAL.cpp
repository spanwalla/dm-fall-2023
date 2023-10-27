//Add getter for digits

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
 std::vector <short> Natural::get_digit(){
     return this->digits;
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



