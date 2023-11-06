#include <iostream>
#include <CLS.h>

int main() {
    Polynomial b({Rational("-10"), Rational("2"), Rational("1")});
    std::cout << b << ' ' << b.DEG_P_N() << std::endl;
    return 0;
}