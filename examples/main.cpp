//
// Created by Chepasov Dmitry (2382) on 27.10.2023.
//

#include <iostream>
#include "CLS.h"

int main() {
    Natural n1("798");
    Natural n2("36");
    Integer n3("-4");
    std::cout << n1.LCM_NN_N(n2) << "!" << std::endl;
    std::cout << n1 << ' ' << n2 << ' ' << n3 << std::endl;
    int a;
    std::cin >> a;
    return 0;
}
