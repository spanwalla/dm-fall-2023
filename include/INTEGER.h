//
// Created by Leonid Ivashinnikov (2382) on 26.10.2023.
//

#ifndef DM_FALL_2023_INTEGER_H
#define DM_FALL_2023_INTEGER_H

#ifdef CLS_EXPORTS
#define CLS __declspec(dllexport)
#else
#define CLS __declspec(dllimport)
#endif

#include "NATURAL.h"
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
    friend CLS std::ostream& operator << (std::ostream& out, const Integer& number); // Оператор вывода в поток.
    int POZ_Z_D();
private:
    Natural number;
    bool sign; // true - если знак отрицательный, для нуля ставить знак false, но логика не должна ломаться если у нуля стоит true
};


#endif //DM_FALL_2023_INTEGER_H
