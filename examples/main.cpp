#include <iostream>
#include <CLS.h>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    Polynomial a("5/2x^100+5");
    Polynomial b(a.DIV_PP_P(Polynomial("8x^2+1")));
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> t = end - start;
    std::cout << t.count() << std::endl;
    std::cout << b << std::endl;
    std::cout << a.FAC_P_Q();
    return 0;
}