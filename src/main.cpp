//
// Created by Chepasov Dmitry (2382) on 27.10.2023.
//

#include <iostream>
#include "Natural/NATURAL.h"
#include "Polinom/POLINOM.h"

int main() {
    Natural n1("512");
    Natural n2("745");
    Polinom test("3:x^3+3x^1+1x^0");
    Polinom test2("0:3x^0");
    Polinom test3("10:x^10+x^9+x^8-x^7-x^6+x^5+x^4+x^3+x^2+x^1+x^0");
    std::cout<<test.LED_P_Q()<<"\ntest2 "<<test2.LED_P_Q()<<"\ntest3 "<<test3.LED_P_Q();
    std::cout << n1.GCF_NN_N(n2) << '\n';
    std::cout << n1.LCM_NN_N(n2) << '\n';
}
