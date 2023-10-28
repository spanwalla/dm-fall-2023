//
// Created by Muravin Egor (2382) on 28.10.2023.
// Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля)
//
//
//
#include "NATURAL.h"

Natural Natural::DIV_NN_Dk(const Natural &number)
{
    Natural first_number;
    Natural temp_one = *this;
    Natural temp_two = number;
    if (temp_one.COM_NN_D(temp_two) == 1)
        std::swap(temp_one, temp_two); // здесь мы кладем большую цифру в temp_one, меньшую в temp_two
    
    if (!temp_two.NZER_N_B())
        throw std::invalid_argument("The number must not be zero!");

    std::size_t index_last_one = temp_one.len() - 1;
    Natural buffer;
    buffer.digits[0] = temp_one.digits[index_last_one]; //добавляем в буффер старшую цифру числа, которое делим
    while(buffer.COM_NN_D(temp_two) == 1)
        buffer.digits.insert(buffer.digits.begin(), temp_one.digits[--index_last_one]);//увеличиваем число в буффере, пока оно не станет больше делителя

     while (buffer.COM_NN_D(temp_two) != 1)
    {
        buffer.SUB_NN_N(temp_two);
        first_number.digits[0]++;//тут мы считаем количество делителей, содержащихся в буффере
    } 
    first_number.MUL_Nk_N(index_last_one);
    return first_number;
}