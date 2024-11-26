class Solution {
public:
    string countAndSay(int n) {
        if(n==1)    return "1";
        string say = countAndSay(n-1);
        string res="";
        for(int i=0;i<say.length();i++)
        {
            char ch = say[i];
            int cnt=1;  // qki abhi us particular character ki frequency 1 hai.
            while(i<say.length()-1  && say[i]==say[i+1])
            {
                cnt++;
                i++;
            }
            res+= to_string(cnt) + string(1,ch);
        }
    return res;
    }
};