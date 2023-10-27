// compare two digits
#include "NATURAL.h"
int Natural::COM_NN_D(Natural& cmp){
        std::vector <short> vcmp = cmp.get_digit();
        if(vcmp.size() == this->digits.size()){
            for (int i = vcmp.size()-1;i>=0;i++){
                if(vcmp[i] != this->digits[i]){
                    if(vcmp[i]>this->digits[i]){
                        return 1;
                    }
                    if(vcmp[i] <this->digits[i]){
                        return 2;
                    }
                    }
                }
                return 0;
            }
        return (this->digits.size() > vcmp.size() ? 2 : 1);
}
