//
// Created by Mihail Fedorov (2382) on 31.10.2023.
//

#ifndef DM_FALL_2023_POLINOM_H
#define DM_FALL_2023_POLINOM_H

// windows
#ifdef CLS_EXPORTS
#define CLS __declspec(dllexport)
#else
#define CLS __declspec(dllimport)
#endif


// linux
/* #ifdef CLS_EXPORTS
#define CLS __attribute__((visibility("default")))
#else
#define CLS
#endif */

#include "RATIONAL.h"
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

class CLS Polinom {
public:
    explicit Polinom(const std::string& content);
    Polinom();
    friend CLS std::ostream& operator << (std::ostream& out, const Polinom& polinom); // Оператор вывода в поток.

private:
    std::vector<Rational> coef_polinom; // вектор, хранящий рациональные коэффициенты
};


#endif //DM_FALL_2023_POLINOM_H
