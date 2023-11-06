#include <iostream>
#include <CLS.h>

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