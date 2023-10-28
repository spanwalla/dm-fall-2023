//Created by Chepasov Dmitry 27.10.23 Group:2382
//Compare two digits

int Natural::COM_NN_D(Natural& cmp){
        if(cmp.digits.size() == this->digits.size()){
            for (int i = cmp.digits.size()-1;i>=0;i--){
                if(cmp.digits[i] != this->digits[i]){
                    if(cmp.digits[i]>this->digits[i]){
                        return 1;
                    }
                    if(cmp.digits[i] <this->digits[i]){
                        return 2;
                    }
                    }
                }
                return 0;
            }
        return (this->digits.size() > cmp.digits.size() ? 2 : 1);

}
