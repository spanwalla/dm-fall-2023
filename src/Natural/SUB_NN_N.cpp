//
// Created by Egor Muravin (2382) on 26.10.2023.
// Вычитание из первого большего натурального числа второго меньшего либо равного.
// С помощью COM_NN_D определяем какое число больше.
// Затем из большего вычитаем меньшее.
//

#define CLS_EXPORTS
#include "NATURAL.h"

void Natural::SUB_NN_N(const Natural &number) {
    Natural temp = number; // создаем переменную, чтобы случайно не изменить входное число
    short carry = 0; // перменная для сохранения битового переполнения
    if (COM_NN_D(temp) == 1) // сравнени чисел, если правое больше - выкидываем исключение
        throw std::logic_error("The first number must be greater than or equal to second");
    short difference; // переменная для хранения результата подсчета
    for (int i = 0; i < len(); ++i) { // запускаем цикл по числу из которого вычитаем (левое)
        if (temp.len() > i) // пока разряды входного числа позволяют вычитать из большего числа
            difference = short(digits[i] - temp.digits[i] - carry); // вычисляем разность текущего разряда числа
        else
            difference = short(digits[i] - carry); // если правое число оказалось меньше, то больше не смотрим на него
        carry = difference < 0 ? 1 : 0; // определем значение переменной переноса, смотря на знак результата difference
        difference = difference < 0 ? difference += 10 : difference; // если difference оказалось меньше 0, то carry флаг устанавливается в 1 и difference увеличивается на 10
        digits[i] = difference; // записываем результат
    }
    clean_zero(); // очищает нули в начале
}

