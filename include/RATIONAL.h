//
// Created by Mihail Fedorov (2382) on 31.10.2023.
//

#ifndef DM_FALL_2023_RATIONAL_H
#define DM_FALL_2023_RATIONAL_H

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

#include "NATURAL.h"
#include "INTEGER.h"
#include <string>
#include <algorithm>
#include <stdexcept>

class CLS Rational {
public:
    explicit Rational(const std::string& number);
    explicit Rational(const Integer& number);
    Rational();
    [[nodiscard]] bool is_zero() const;
    [[nodiscard]] bool is_sign() const;
    friend CLS std::ostream& operator << (std::ostream& out, const Rational& number); // Оператор вывода в поток.

    [[nodiscard]] bool INT_Q_B() const;
    static Rational TRANS_Z_Q(const Integer& number);
    [[nodiscard]] Integer TRANS_Q_Z() const;
    void RED_Q_Q();
    void ADD_QQ_Q(const Rational& number);
    void SUB_QQ_Q(const Rational& number);
    void MUL_QQ_Q(const Rational& number);
    void DIV_QQ_Q(const Rational& number);

private:
    Integer numerator; // числитель
    Natural denominator; // знаменатель
};


#endif //DM_FALL_2023_RATIONAL_H
