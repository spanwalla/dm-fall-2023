// compare two digits
#include "NATURAL.h"
int Natural::COM_NN_D(Natural cmp){
        std::vector <short> vcmp = cmp.get_digit();
        int len = std::max(this->digits.size(),vcmp.size());//Берем максимальную длину
        int count_dif_numbers = 0;
        if(vcmp.size() == this->digits.size()){
            for (int i = 0;i<vcmp.size();i++){
                if(vcmp[i] != this->digits[i]){
                    if(vcmp[i]>this->digits[i]){
                        return 1;
                        break;
                    }
                    if(vcmp[i] <this->digits[i]){
                        return 2;
                        break;
                    }
                    }
                }
            if(count_dif_numbers == 0)
                return 0;
            }
        else if (len == vcmp.size())
            return 1;
        else if (len == this->digits.size())
            return 2;

}
