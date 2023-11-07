//
// Created by Mihail Fedorov (2382) on 31.10.2023.
// Класс многочленов, в векторе из рациональных чисел хранятся коэффициенты.
// На нулевой позиции находится свободный член, на последней старший.
// Очень желательно не забывать убирать незначащие нули, если они могут появиться.
//

#ifndef DM_FALL_2023_POLYNOMIAL_H
#define DM_FALL_2023_POLYNOMIAL_H

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
    explicit Polynomial(std::vector<Rational> coefficients);
    Polynomial();
    bool is_zero();
    friend CLS std::ostream& operator << (std::ostream& out, const Polynomial& polynomial); // Оператор вывода в поток.

    void MUL_PQ_P(const Rational& number);
    void MUL_Pxk_P(unsigned long long int k);
    [[nodiscard]] Rational LED_P_Q();
    [[nodiscard]] int DEG_P_N() const;

private:
    std::vector<Rational> coefficients; // вектор, хранящий рациональные коэффициенты, индекс - степень члена
    void clean_zero();
};


#endif //DM_FALL_2023_POLYNOMIAL_H
