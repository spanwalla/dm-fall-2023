//
// Created by Mihail Fedorov (2382) on 13.11.2023.
// Преобразование многочлена - кратные корни в простые.
//

#define CLS_EXPORTS
#include "POLYNOMIAL.h"

Polynomial Polynomial::NMR_P_P() const {
    // проверка на нуль
    if (this->is_zero())
        throw std::invalid_argument("Division by zero");
    // возвращает требуемое значение
    return std::move(this->DIV_PP_P(this->GCF_PP_P(this->DEP_P_P())));
}
