//
// Created by Mihail Fedorov (2382) on 31.10.2023.
//

#ifndef DM_FALL_2023_POLINOM_H
#define DM_FALL_2023_POLINOM_H

#ifdef _WIN32
    // Экспорт символов для Windows
    #ifdef CLS_EXPORTS
        #define CLS __declspec(dllexport)
    #else
        #define CLS __declspec(dllimport)
    #endif
#else
    // Экспорт символов для Linux
    #define CLS __attribute__((visibility("default")))
#endif

#include "RATIONAL.h"
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

class CLS Polynomial {
public:
    explicit Polynomial(const std::string& content);
    Polynomial();
    friend CLS std::ostream& operator << (std::ostream& out, const Polynomial& polinom); // Оператор вывода в поток.

private:
    std::vector<Rational> coef_polinom; // вектор, хранящий рациональные коэффициенты
};


#endif //DM_FALL_2023_POLINOM_H
