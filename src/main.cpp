//
// Created by Chepasov Dmitry (2382) on 27.10.2023.
//

#include <iostream>
#include "Natural/NATURAL.h"

int main() {
    Natural n1("101");
    Natural n2("33");
    n1.MUL_NN_N(n2);
    std::cout << n1 << '\n';
}
