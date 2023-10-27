#ifndef u_num_cpp
#define u_num_cpp

#include "u_num.h"
#include <stdexcept>
#include <algorithm>
#include <regex>

bool UNum::is_natural_num(const std::string num) {
    std::regex pattern("[0-9][0-9]*");
    return std::regex_match(num, pattern);
}

void UNum::swap(UNum& other) {
    std::swap(this->num, other.num);
    std::swap(this->size, other.size);
}

UNum::UNum() : size(0), num(nullptr) {}

UNum::UNum(const std::string const_num_str) : UNum() {
    if (!this->is_natural_num(const_num_str))
        throw std::invalid_argument("Object UNum exept a natural number.");

    // копируем строку
    std::string num_str(const_num_str);

    // инициализируем size = (num_str.size() + 1) / 2, так как мы храним в каждой учуйке массива число от 0 до 99
    // и выделяем память под массив
    this->size = (num_str.size() + 1) / 2;
    this->num = new char[this->size];

    // записываем по две цифры в массив в обратном порядке
    // то есть число 12345 запишется как [ 45, 23, 1 ]
    for (unsigned long long i = 0; i < this->size; ++i) {
        std::string tmp = num_str.substr((num_str.size() - 2) < num_str.size() ? (num_str.size() - 2) : 0);
        num_str = num_str.substr(0, num_str.size() - 2);
        this->num[i] = std::stoi(tmp);
    }
}

UNum::UNum(const UNum& other) : size(other.size) {
    this->num = new char[this->size];
    std::copy(other.num, other.num + other.size, this->num);
}

UNum::UNum(UNum&& other) : size(0), num(nullptr) { this->swap(other); }

UNum::UNum(unsigned long long size) : size(size) { this->num = new char[size]; }

UNum::~UNum() { delete [] this->num; }

UNum& UNum::operator=(const UNum& other) {
    if (this == &other)
        return *this;
    
    UNum tmp(other);
    this->swap(tmp);
    return *this;
}

UNum& UNum::operator=(UNum&& other) {
    if (this == &other)
        return *this;
    
    this->swap(other);
    return *this;
}

std::string UNum::str_num() const {
    std::string str_num = "";
    for (unsigned long long i = 0; i < this->size; ++i) {
        str_num = std::to_string(this->num[i]) + str_num;
        if (str_num.size() % 2)
            str_num = '0' + str_num;
    }

    if (str_num[0] == '0') 
        str_num = str_num.substr(1);

    return str_num;
}

#endif