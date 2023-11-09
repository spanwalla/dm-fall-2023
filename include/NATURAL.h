//
// Created by Leonid Ivashinnikov (2382) on 25.10.2023.
//

#ifndef DM_FALL_2023_NATURAL_H
#define DM_FALL_2023_NATURAL_H

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

#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <ranges>
#include <iostream>

class CLS Natural {
public:
    explicit Natural(const std::string& number);
    explicit Natural(long long int num);
    Natural();
    friend CLS std::ostream& operator << (std::ostream& out, const Natural& number); // оператор вывода в поток
    Natural& operator=(const Natural& number);
    friend CLS bool operator==(const Natural& number1, const Natural& number2);
    friend CLS bool operator!=(const Natural& number1, const Natural& number2);
    friend CLS bool operator>=(const Natural& number1, const Natural& number2);
    friend CLS bool operator<=(const Natural& number1, const Natural& number2);
    friend CLS bool operator>(const Natural& number1, const Natural& number2);
    friend CLS bool operator<(const Natural& number1, const Natural& number2);
    Natural& operator++();
    Natural operator++(int);
    Natural& operator--();
    Natural operator--(int);

    [[nodiscard]] int COM_NN_D(const Natural& cmp) const;
    [[nodiscard]] bool NZER_N_B() const;
    void ADD_1N_N();
    void ADD_NN_N(const Natural& number);
    void SUB_NN_N(const Natural &number);
    void MUL_ND_N(short digit);
    void MUL_Nk_N(unsigned long long int k);
    void MUL_NN_N(Natural number);
    void SUB_NDN_N(const Natural &number, short digit);
    [[nodiscard]] Natural DIV_NN_Dk(const Natural &number) const;
    [[nodiscard]] Natural DIV_NN_N(const Natural& number) const;
    [[nodiscard]] Natural MOD_NN_N(const Natural& number) const;
    [[nodiscard]] Natural GCF_NN_N(const Natural& number) const;
    [[nodiscard]] Natural LCM_NN_N(const Natural& number) const;

private:
    std::vector<short> digits; // массив цифр, цифры записаны в обратном порядке

    [[nodiscard]] std::size_t len() const;
    void zfill(unsigned count);
    void clean_zero(); // удаляет незначащие нули
};


#endif //DM_FALL_2023_NATURAL_H
