//
// Created by Leonid Ivashinnikov (2382) on 26.10.2023.
// Класс целых чисел. Поля: число типа Natural и флаг знака. true - если отрицательный, false если больше нуля.
// Для нуля желательно устанавливать в false, но от этого не должна меняться логика алгоритмов.
// Создание объекта из строки, числа long long int. Значение по умолчанию: 0.
//

#define CLS_EXPORTS
#include "INTEGER.h"

Integer::Integer(const std::string &number) {
    if (number.empty())
        Integer(); // вызываем конструктор по умолчанию для пустых строк
    if (number[0] == '-' || number[0] == '+') { // если указан знак
        if (number.size() == 1)
            throw std::invalid_argument("You can't just give us a sign, lol.");
        this->number = Natural(number.substr(1));
        this->sign = this->number.NZER_N_B() && number[0] == '-'; // чтобы не создавать -0.
    } else {
        this->number = Natural(number);
        this->sign = false;
    }
}

std::ostream& operator << (std::ostream &out, const Integer &object) {
    if (object.number.NZER_N_B()) {
        if (object.sign)
            out << "-";
        out << object.number;
    }
    else
        out << "0";
    return out;
}

Integer::Integer(): sign(false), number(Natural(0)) {}
Integer::Integer(long long int number): sign(number < 0), number(Natural(std::abs(number))) {}
Integer::Integer(const Natural &number): sign(false), number(number) {}


bool Integer::operator==(const Integer& number){
    return ((this->number == number.number) && (this->sign == number.sign));
}


bool Integer::operator>=(const Integer& number){
    Integer temp(*this);
    temp.SUB_ZZ_Z(number);
    return ((!temp.sign) || (temp.number == Natural()));
}


bool Integer::operator<=(const Integer& number){
    Integer temp(*this);
    temp.SUB_ZZ_Z(number);
    return ((temp.sign) || (temp.number == Natural()));
}


bool Integer::operator>(const Integer& number){
    Integer temp(*this);
    temp.SUB_ZZ_Z(number);
    return (!temp.sign);
}


bool Integer::operator<(const Integer& number){
    Integer temp(*this);
    temp.SUB_ZZ_Z(number);
    return (temp.sign);
}

Integer& Integer::operator++(){
    this->ADD_ZZ_Z(Integer(1));
    return *this;
}

Integer& Integer::operator++(int){
    this->ADD_ZZ_Z(Integer(1));
    return *this;
}

Integer& Integer::operator--(){
    this->SUB_ZZ_Z(Integer(1));
    return *this;
}

Integer& Integer::operator--(int){
    this->SUB_ZZ_Z(Integer(1));
    return *this;
}