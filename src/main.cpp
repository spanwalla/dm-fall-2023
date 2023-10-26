//
// Created by Leonid Ivashinnikov (2382) on 25.10.2023.
//

#include <iostream>
#include "Natural/NATURAL.h"

int main() {
    Natural n("451");
    n.MUL_ND_NN(1);
    std::cout << n << std::endl;
}