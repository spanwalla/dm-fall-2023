// Created by Semenenko Anna 31.10.2023
// Преобразование натурального в целое
// Integer new_integer_obj = Integer::TRANS_N_Z(nat_obj);

#include "INTEGER.h"

Integer Integer::TRANS_N_Z(Natural& nat){
    return Integer(nat);
}