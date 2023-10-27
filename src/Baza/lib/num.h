#ifndef num_h
#define num_h

#include "u_num.h"
#include <string>

class Num {

    UNum num;
    bool is_negative;

    bool is_integer(std::string);

    void swap(Num&);

public:

    Num();
    Num(const std::string);
    Num(const Num&);
    Num(Num&&);

    Num& operator=(const Num&);
    Num& operator=(Num&&);

    std::string str_num() const;

};

#endif