// Created by Bukharin Maxim (2382) on 04.11.2023.
// Проверка на целое

#define CLS_EXPORTS
#include "RATIONAL.h"

bool Rational::INT_Q_B() const {
    Natural GCF = this->denominator.GCF_NN_N(this->numerator.ABS_Z_Z().TRANS_Z_N()); // находим НОД числителя и знаменателя
    return this->denominator.COM_NN_D(GCF) == 0; // возвращаем, равен ли НОД знаменателю
}
