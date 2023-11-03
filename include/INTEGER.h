//
// Created by Leonid Ivashinnikov (2382) on 26.10.2023.
//

#ifndef DM_FALL_2023_INTEGER_H
#define DM_FALL_2023_INTEGER_H

// windows
#ifdef CLS_EXPORTS
#define CLS __declspec(dllexport)
#else
#define CLS __declspec(dllimport)
#endif


// linux
/* #ifdef CLS_EXPORTS
#define CLS __attribute__((visibility("default")))
#else
#define CLS
#endif */

#include "NATURAL.h"
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

class CLS Integer {
public:
    explicit Integer(const std::string& number);
    explicit Integer(long long int number);
    explicit Integer(const Natural& number);
    Integer();
    friend CLS std::ostream& operator << (std::ostream& out, const Integer& number); // Оператор вывода в поток.

    Integer ABS_Z_Z() const;
    int POZ_Z_D() const;
    void MUL_ZM_Z();
    static Integer TRANS_N_Z(const Natural& nat);
    Natural TRANS_Z_N() const;
    void ADD_ZZ_Z(Integer b);
    void MUL_ZZ_Z(Integer num);
    Integer DIV_ZZ_Z(const Integer& divisor) const;
    void SUB_ZZ_Z(Integer b);
    Integer MOD_ZZ_Z(const Integer &num) const;
private:
    Natural number;
    bool sign; // true - если знак отрицательный, для нуля ставить знак false, но логика не должна ломаться если у нуля стоит true
};


#endif //DM_FALL_2023_INTEGER_H
