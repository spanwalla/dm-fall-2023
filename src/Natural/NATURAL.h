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

    short COM_NN_D(const Natural& number) const; // тут немного поменял
    bool NZER_N_B() const;
    void ADD_1N_N();
    
    //немного добавил
    size_t len() const;
    void zfill(unsigned count);
    Natural& operator=(const Natural& number);
    void clean_zero(); // удаляет незнач. нули
    void SUB_NN_N(const Natural &number);


private:
    std::vector<short> digits; // массив цифр, цифры записаны в обратном порядке
};


#endif //DM_FALL_2023_NATURAL_H
