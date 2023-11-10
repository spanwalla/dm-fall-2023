#include <iostream>
#include <CLS.h>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    Polynomial a("x^10+2x+1");
    Polynomial b(a.MOD_PP_P(Polynomial("-x^3+8x^2")));
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> t = end - start;
    std::cout << t.count() << std::endl;
    std::cout << b << std::endl;
    return 0;
}