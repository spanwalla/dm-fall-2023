// Created by Bukharin Maxim (2382) on 06.11.2023.
// Сокращение дроби

#define CLS_EXPORTS
#include "RATIONAL.h"

void Rational::RED_Q_Q() {
    Natural GCF = this->denominator.GCF_NN_N(this->numerator.ABS_Z_Z().TRANS_Z_N()); // находим НОД числителя и знаменателя
    this->numerator = this->numerator.DIV_ZZ_Z(Integer(GCF)); // делим числитель на НОД
    this->denominator = this->denominator.DIV_NN_N(GCF); // делим знаменатель на НОД
}