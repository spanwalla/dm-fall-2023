// Created by Semenenko Anna 31.10.2023
// Преобразование натурального в целое
// у класса целых есть поле натурального числа, мы просто возвращаем это поле

#include "INTEGER.h"

Natural& Integer::TRANS_Z_N(){
    if(!this->sign)
        return this->number;
}
