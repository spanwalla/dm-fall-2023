#include <iostream>
#include "CLS.h"

int main() {
    Natural n(0);
    std::cout << n << '\n';
    ++n;
    std::cout << n << '\n';
    n++;
    std::cout << n << '\n';
    --n;
    std::cout << n << '\n';
    n--;
    std::cout << n << '\n';
    return 0;
}