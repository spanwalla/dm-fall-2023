//
// Created by Leonid Ivashinnikov (2382) on 25.10.2023.
//

#include <iostream>
#include "Natural/NATURAL.h"

int main() {
    Natural n("10");
    Natural t("0");
    std::cout << n << ' ' << t << '\n';
    std::cout << n.SUB_NN_N(t) <<  '\n';
   // std::cout << n.COM_NN_D(t) << '\n';
}