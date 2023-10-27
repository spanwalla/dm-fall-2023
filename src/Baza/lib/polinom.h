#ifndef polinom_h
#define polinom_n

#include "rational_fraction.h"
#include <map>
#include <iostream>

class Polinom {

    std::map<unsigned long long, RatFraction> pol;

public:

    Polinom(const std::string);

    std::string str_polinom() const;

};

#endif