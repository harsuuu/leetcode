class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int dollar_5 = 0;
        int dollar_10 = 0;

        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                dollar_5++;
            } 
            else if(bills[i] == 10) {
                if(dollar_5 == 0) {
                    return false;
                }
                dollar_5--;
                dollar_10++;
            } 
            else{ // bills[i] == 20
                if(dollar_10 > 0 && dollar_5 > 0) {
                    dollar_10--;
                    dollar_5--;
                }else if(dollar_5 >= 3) {
                    dollar_5 -= 3;
                }else{
                    return false;
                }
            }
        }
    return true;
    }
};