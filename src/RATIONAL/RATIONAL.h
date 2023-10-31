//
// Created by Mihail Fedorov (2382) on 31.10.2023.
//

#ifndef DM_FALL_2023_RATIONAL_H
#define DM_FALL_2023_RATIONAL_H

#include "../Natural/NATURAL.h"
#include "../Integer/INTEGER.h"
#include <string>
#include <algorithm>
#include <stdexcept>

class Rational {
public:
    explicit Rational(const std::string& number);
    Rational();
    bool is_zero() const;
    bool is_sign() const;
    friend std::ostream& operator << (std::ostream& out, const Rational& number); // Оператор вывода в поток.

private:
    Integer numerator; // числитель
    Natural denominator; // знаменатель
};


#endif //DM_FALL_2023_RATIONAL_H
