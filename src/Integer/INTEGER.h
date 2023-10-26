//
// Created by Leonid Ivashinnikov (2382) on 26.10.2023.
//

#ifndef DM_FALL_2023_INTEGER_H
#define DM_FALL_2023_INTEGER_H

#include "../Natural/NATURAL.h"
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Integer {
public:
    explicit Integer(const std::string& number);
    explicit Integer(long long int number);
    explicit Integer(Natural& number);
    Integer();
    friend std::ostream& operator << (std::ostream& out, const Integer& number); // Оператор вывода в поток.
    // Перегрузить оператор взятия по индексу.
    // Доступ к натуральному числу отсюда или дублировать функции Natural или ваши идеи

private:
    Natural number;
    bool sign; // true - если знак отрицательный, для нуля ставить знак false, но логика не должна ломаться если у нуля стоит true
};


#endif //DM_FALL_2023_INTEGER_H
