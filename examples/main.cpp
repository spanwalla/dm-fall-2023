#include <iostream>
#include "CLS.h"

int main() {
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