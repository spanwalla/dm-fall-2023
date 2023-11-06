#include <iostream>
#include <CLS.h>

int main() {
    Polynomial b({Rational("5"), Rational("3")});
    b.MUL_Pxk_P(4);
    std::cout << b << std::endl;
    return 0;
}