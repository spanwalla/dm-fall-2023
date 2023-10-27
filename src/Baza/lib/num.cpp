#ifndef num_cpp
#define num_cpp

#include "num.h"
#include <stdexcept>
#include <algorithm>
#include <regex>

bool Num::is_integer(std::string num) {
    std::regex pattern("-?[0-9][0-9]*");
    return std::regex_match(num, pattern);
}

void Num::swap(Num& other) {
    std::swap(this->is_negative, other.is_negative);
    std::swap(this->num, other.num);
}

Num::Num() : is_negative(false) {}

Num::Num(const std::string const_num_str) : Num() {
    if (!this->is_integer(const_num_str))
        throw std::invalid_argument("Object Num exept an intenger."); 

    std::string num_str(const_num_str);

    if (const_num_str[0] == '-') {
        this->is_negative = true;
        num_str = num_str.substr(1);
    }

    UNum tmp(num_str);
    this->num = std::move(tmp);
}

Num::Num(const Num& other) : is_negative(other.is_negative), num(other.num) {}

Num::Num(Num&& other) : Num() { this->swap(other); }

Num& Num::operator=(const Num& other) {
    if (this == &other)
        return *this;
    
    Num tmp(other);
    this->swap(tmp);
    return *this;
}

Num& Num::operator=(Num&& other) {
    if (this == &other)
        return *this;
    
    this->swap(other);
    return *this;
}

std::string Num::str_num() const { return (this->is_negative ? "-" : "") + this->num.str_num(); }

#endif