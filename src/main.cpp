//
// Created by Chepasov Dmitry (2382) on 27.10.2023.
//

#include <iostream>
#include "Natural/NATURAL.h"

int main() {
    Natural n1("233");
    Natural n2("5");
    std::cout << n1.MOD_NN_N(n2) << '\n';
}
