//
// Created by Mihail Fedorov (2382) on 31.10.2023.
//

#ifndef DM_FALL_2023_POLINOM_H
#define DM_FALL_2023_POLINOM_H

#include "../RATIONAL/RATIONAL.h"
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Polinom {
public:
    explicit Polinom(const std::string& content);
    Polinom();
    friend std::ostream& operator << (std::ostream& out, const Polinom& polinom); // Оператор вывода в поток.

private:
    std::vector<Rational> polinom; // вектор, хранящий рациональные коэффициенты
};


#endif //DM_FALL_2023_POLINOM_H
