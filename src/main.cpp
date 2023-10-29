//
// Created by Leonid Ivashinnikov (2382) on 25.10.2023.
//

#include <iostream>
#include "Natural/NATURAL.h"

int main() {
    Natural n1("1231");
    Natural n2("12123782137");
    n1.ADD_NN_N(n2);
    std::cout << n2 << std::endl;
}
