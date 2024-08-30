class Solution {
public:
    string reverseOnlyLetters(string s) {
         int j = s.length() - 1;
        int i = 0;
        while (i < j) {
            if (!isalpha(s[i])) {
                i++;
            }else if (!isalpha(s[j])) {
                j--;
            } 
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
    return s;
    }
};