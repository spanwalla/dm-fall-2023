// Created by Shegoleva Nadezda gr2383 on 31.10.2023.
//Функция определения положительности числа

#include "INTEGER.h"

int Integer::POZ_Z_D(){
    Natural value = this->number;
    if (value.NZER_N_B()){
        return this->sign ? 1 : 2;}
    else{
        return 0;
    }
}

