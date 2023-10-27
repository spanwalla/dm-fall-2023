//
// Created by Leonid Ivashinnikov (2382) on 25.10.2023.
//

#include <iostream>
#include "Natural/NATURAL.h"

int main() {
    Natural n1("34345");
    Natural n2("23142");
    //n.COM_NN_D("154");
    std::cout <<n1.COM_NN_D(n2) << std::endl;
}
