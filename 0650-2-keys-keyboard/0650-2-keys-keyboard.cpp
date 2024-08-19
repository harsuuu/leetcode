class Solution {
public: 
    int solve(int currA,int clip,int n)
    {
        if(currA==n)    return 0;
        if(currA>n)     return 100000;

        int copyAllPaste = 1 + 1 + solve(currA + currA, currA, n);

        int paste = 1 + solve(currA+clip,clip,n);

        return min(copyAllPaste,paste);
    }

    int minSteps(int n) {
        if(n==1)    return 0;

        return 1 + solve(1,1,n);
    }
};