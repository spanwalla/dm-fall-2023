//
// Created by Chepasov Dmitry (2382) on 27.10.2023.
//

#include <iostream>
#include "Natural/NATURAL.h"

int main() {
    Natural n1("100000");
    Natural n2("53333");
    n1.ADD_NN_N(n2);
    std::cout << "summ:" <<n1 << std::endl;
}
