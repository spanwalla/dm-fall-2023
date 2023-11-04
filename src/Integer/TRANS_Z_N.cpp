// Created by Anna Semenenko (2382) on 31.10.2023.
// Преобразование целого в натуральное.
// у класса целых есть поле натурального числа, мы просто возвращаем это поле.

#define CLS_EXPORTS
#include "INTEGER.h"

Natural Integer::TRANS_Z_N() const {
    if (!this->sign)
        return this->number;
    else
        throw std::logic_error("Integer must be non-negative");
}
