#include <iostream>
#include <CLS.h>
#include <chrono>

int main() {
    Polynomial a("x^5-15x^3+10x^2+60x-72");
    std::cout << a.NMR_P_P();
    return 0;
}