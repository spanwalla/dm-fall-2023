#include <iostream>
#include <CLS.h>

int main() {
    Polynomial b({Rational("-10"), Rational("2"), Rational("1")});
    std::cout << b << ' ' << b.DEG_P_N() << std::endl;
    b.MUL_Pxk_P(4);
    std::cout << b << std::endl;
    return 0;
}