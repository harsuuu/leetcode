class Solution {
public:
    int reverse(int x) {
        if(x<=INT_MIN)       //-2^31 == INT_MIN (Agr x int_min se bhi km hia to return 0)
        {
            return 0;
        }
        int rev=0;
        bool isNeg=false;
        if(x<0)
        {
            isNeg=true;
            x=-x;
        }
        while(x>0)
        {
            if(rev > INT_MAX/10)   
            {
                return 0;          //agr answer 2^31-1 == INT_MAX/10 se bda aaye to return 0;
            }
            int digit=x%10;
            rev=(rev*10)+digit;
            x=x/10;
        }
    return isNeg ?-rev : rev;   
    }
};