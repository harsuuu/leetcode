class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
        {
            return false;
        }
        double f=(double)log10(n)/log10(4);
        return ceil(f)==floor(f);
    }
};