class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length()-1;
        int m = b.length()-1;
        char carry='0';
        string ans="";
        while (n >= 0 || m >= 0) {
            int x = (n >= 0) ? a[n] : '0';  // Check bounds before accessing a[n]
            int y = (m >= 0) ? b[m] : '0';  // Check bounds before accessing b[m]
            
            if(x=='1' && y=='1')
            {
                if(carry=='1')
                {
                    ans+='1';
                    carry='1';
                }
                else{
                    ans+='0';
                    carry='1';
                }
            }
            else if (x =='1'&& y=='0')
            {
                if (carry=='1')
                {
                    ans+='0';
                    carry='1';
                }
                else
                {
                    ans+='1';
                }
            }
            else if(x=='0' && y=='1')
            {
                if(carry=='1')
                {
                    ans+='0';
                    carry='1';
                }
                else{
                    ans+='1';
                }
            }
            else if(x=='0' && y=='0')
            {
                if(carry=='1')
                {
                    ans+='1';
                    carry='0';
                }
                else{
                    ans+='0';
                }
            } 
        n--;
        m--;
        } 
        if(carry=='1')  ans+=carry;
        reverse(ans.begin(),ans.end());
    return ans;
    }
};