//Created by Chepasov_Dmitry GR 2382 07.11.23
#include "POLYNOMIAL.h"
#define CLS_EXPORTS
Rational Polynomial::LED_P_Q(){
        this->clean_zero();
        return this->coefficients.back();
}
