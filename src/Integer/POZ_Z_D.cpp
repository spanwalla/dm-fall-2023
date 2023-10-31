// Created by Shegoleva Nadezda gr2383 on 31.10.2023.
//Функция определения положительности числа
//Если число положительное, функция вернет 2
//Если отрицательное, функция вернет 1
//Если число является нулем, функция вернет 0

#include "INTEGER.h"

int Integer::POZ_Z_D(){
    Natural value = this->number;
    if (value.NZER_N_B()){
        return this->sign ? 1 : 2;}
    else{
        return 0;
    }
}

