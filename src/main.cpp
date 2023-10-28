//
// Created by Leonid Ivashinnikov (2382) on 25.10.2023.
//

#include <iostream>
#include "Natural/NATURAL.h"

int main() {
    Natural n1("1350123204123000");
    Natural n2("213042130");
    n1.ADD_NN_N(n2);
    std::cout << n1 << std::endl;
}
