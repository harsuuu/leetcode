class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0)
        {
            return true;
        }
        if(x<0)
        {
            return false;
        }
        long rev = 0;
        int temp = x;
        while(temp!=0)
        {
            int rem=temp%10;
            temp=temp/10;
            rev=rev*10+rem;
        }
        if(x==rev)
        {
            return true;
        }
        else
        {
            return false;
        }
    }  
};