class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        stack<char>st;
        for(char c : s) {
            if(!st.empty() && ((c == 'B' && st.top() == 'A') || (c == 'D' && st.top() == 'C'))) {
                st.pop();  // Remove "AB" or "CD"
            } else {
                st.push(c);  // Push current character to stack if no removal is possible
            }
        }
    
    return st.size();
    }
};