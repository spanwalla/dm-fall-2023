//
// Created by Leonid Ivashinnikov (2382) on 25.10.2023.
//

#include <iostream>
#include "Natural/NATURAL.h"

int main() {
    Natural n1("14205");
    Natural n2("14206");
    //n.COM_NN_D("154");
    std::cout <<n1.COM_NN_D(n2) << std::endl;
}