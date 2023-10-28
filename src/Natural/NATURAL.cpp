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
    clean_zero(); // Убрать незначащие нули.
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

std::size_t Natural::len() const {
    return digits.size();
}

void Natural::clean_zero() {
    while (digits.size() > 1 && digits.back() == 0)
        digits.pop_back();
}

void Natural::zfill(unsigned count) {
    digits.insert(digits.end(), count, 0);
}

Natural &Natural::operator=(const Natural &number) {
    if (this == &number)
        return *this;
    digits.clear();
    std::copy(number.digits.begin(), number.digits.end(), std::back_inserter(digits));
    return *this;
}
