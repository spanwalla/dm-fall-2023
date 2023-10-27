#ifndef u_num_h
#define u_num_h

#include <string>

class UNum {

    char* num;
    unsigned long long size;

    UNum(unsigned long long);

    bool is_natural_num(std::string);

    void swap(UNum&);

public:

    UNum();
    UNum(const std::string);
    UNum(const UNum&);
    UNum(UNum&&);
    ~UNum();

    UNum& operator=(const UNum&);
    UNum& operator=(UNum&&);

    // UNum operator-() const;
    // UNum operator+(const UNum&) const;
    // UNum operator-(const UNum&) const;

    std::string str_num() const;

};

#endif