#include <iostream>
#include "CLS.h"

int main() {
    Integer i(100);
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