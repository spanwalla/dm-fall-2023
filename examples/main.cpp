#include <iostream>
#include <CLS.h>

int main() {
    Polynomial b({Rational("-10")});
    std::cout << b << std::endl;
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
    Integer i(-1);
    std::cout << i << '\n';
    i++;
    std::cout << i << '\n';
    ++i;
    std::cout << i << '\n';
    i--;
    std::cout << i << '\n';
    --i;
    std::cout << i << '\n';
    return 0;
}