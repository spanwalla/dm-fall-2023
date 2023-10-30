//
// Created by Chepasov Dmitry (2382) on 27.10.2023.
//

#include <iostream>
#include "Natural/NATURAL.h"

int main() {
    Natural n1("512");
    Natural n2("745");
    std::cout << n1.GCF_NN_N(n2) << '\n';
    std::cout << n1.LCM_NN_N(n2) << '\n';
}
