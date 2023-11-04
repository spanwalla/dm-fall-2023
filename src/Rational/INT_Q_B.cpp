// Created by Bukharin Maxim (2382) on 04.11.2023.
// Проверка на целое

#include "RATIONAL.h"

bool Rational::INT_Q_B() const {
<<<<<<< HEAD
    Natural GCF = this->denominator.GCF_NN_N(this->numerator.ABS_Z_Z().TRANS_Z_N()); // находим НОД делителя и знаменателя
=======
    Natural GCF = this->denominator.GCF_NN_N(this->numerator.ABS_Z_Z().TRANS_Z_N()); // находим НОД числителя и знаменателя
>>>>>>> 6de5b44 (Проверка рационального на целое, теперь учитываются случаи 15/3, 6/2 и тд.)
    return this->denominator.COM_NN_D(GCF) == 0; // возвращаем, равен ли НОД знаменателю
}