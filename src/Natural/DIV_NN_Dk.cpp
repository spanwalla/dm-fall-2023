//
// Created by Muravin Egor (2382) on 28.10.2023.
// Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля)
//

#define CLS_EXPORTS
#include "NATURAL.h"

Natural Natural::DIV_NN_Dk(const Natural &number) const
{
    Natural first_number;
    if (COM_NN_D(number) == 1)
        throw std::logic_error("The first number must be greater than the second"); // выкидываем ошибку, если 2 число больше 1

    if (!number.NZER_N_B())
        throw std::invalid_argument("The number must not be zero!");

    std::size_t index_last_one = len() - 1;
    Natural buffer;
    buffer.digits[0] = digits[index_last_one]; // добавляем в буффер старшую цифру числа, которое делим
    while (buffer.COM_NN_D(number) == 1)
        buffer.digits.insert(buffer.digits.begin(), digits[--index_last_one]); // увеличиваем число в буффере, пока оно не станет больше делителя

    while (buffer.COM_NN_D(number) != 1)
    {
        buffer.SUB_NN_N(number);
        first_number.digits[0]++; // тут мы считаем количество делителей, содержащихся в буффере
    }
    first_number.MUL_Nk_N(index_last_one);
    return first_number;
}