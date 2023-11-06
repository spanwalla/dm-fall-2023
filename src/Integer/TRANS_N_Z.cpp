// Created by Anna Semenenko (2382) on 31.10.2023.
// Преобразование натурального в целое.
// Integer new_integer_obj = Integer::TRANS_N_Z(nat_obj);

#define CLS_EXPORTS
#include "INTEGER.h"

Integer Integer::TRANS_N_Z(const Natural& nat) {
    return Integer(nat);
}