// Created by Semenenko Anna 31.10.2023
// Преобразование натурального в целое
// static метод, чтобы не создавать временный объект при вызове
// Integer new_integer_obj = Integer::TRANS_N_Z(nat_obj);

#include "INTEGER.h"

Integer Integer::TRANS_N_Z(Natural& nat){
    return Integer(nat);
}