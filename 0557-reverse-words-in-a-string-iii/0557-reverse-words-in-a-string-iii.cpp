class Solution {
public:
    string reverseWords(string s) {
        int l=0;
        int r=0;
        while(l<s.size())   //ye loop tb tk chlaye jb tk string end na ho jaye.
        {
            while(r<s.size() && s[r]!=' ')
            {
                r++;   //ye r white space pr jakr ruk jayega.
            }
            reverse(s.begin()+l,s.begin()+r);
            l=r+1;
            r=l;
        }
    return s;
    }
};