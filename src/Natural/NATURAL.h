//
// Created by Leonid Ivashinnikov (2382) on 25.10.2023.
//

#ifndef DM_FALL_2023_NATURAL_H
#define DM_FALL_2023_NATURAL_H

#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <ranges>
#include <iostream>

class Natural {
public:
    explicit Natural(const std::string& number);
    explicit Natural(long long int num);
    Natural();
    friend std::ostream& operator << (std::ostream& out, const Natural& number); // оператор вывода в поток
    Natural& operator=(const Natural& number);

    [[nodiscard]] int COM_NN_D(const Natural& cmp);
    [[nodiscard]] bool NZER_N_B() const;
    void ADD_NN_N(const Natural& number);
    void SUB_NN_N(const Natural &number);
    void MUL_ND_N(short digit);
    void MUL_Nk_N(unsigned long long int k);
    void MUL_NN_N(Natural number);
    void SUB_NDN_N(const Natural &number, short digit);
    Natural DIV_NN_Dk(const Natural &number);
    Natural DIV_NN_N(Natural& number);
    Natural MOD_NN_N(const Natural& number);

private:
    std::vector<short> digits; // массив цифр, цифры записаны в обратном порядке

    [[nodiscard]] std::size_t len() const;
    void zfill(unsigned count);
    void clean_zero(); // удаляет незначащие нули
};


#endif //DM_FALL_2023_NATURAL_H
