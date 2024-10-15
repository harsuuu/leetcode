class Solution {
public:
    long long minimumSteps(string s) {
        long long n = s.length();
        long long black=0;
        long long  swap=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')   cnt++;
            else{
                swap+=cnt;
            }
        }
    return swap;
    } 
};