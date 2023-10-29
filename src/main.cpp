//
// Created by Leonid Ivashinnikov (2382) on 25.10.2023.
//

#include <iostream>
#include "Natural/NATURAL.h"

int main() {
    Natural n1("99");
    Natural n2("99");
    n1.ADD_NN_N(n2);
    std::cout << "\nn1:" <<n1 << std::endl;
}
