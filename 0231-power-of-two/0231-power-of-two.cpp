class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        {
            return false;
        }
        double f=(double)log10(n)/log10(2);
        return ceil(f)==floor(f);
    }
};