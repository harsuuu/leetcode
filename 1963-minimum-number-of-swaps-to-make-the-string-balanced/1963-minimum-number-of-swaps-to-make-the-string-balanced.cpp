class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(auto it:s){
            if(!st.empty() && it==']')
            {
                st.pop();
            }
            else if(it=='[')
            {
                st.push(it);
            }
        }
        int size = st.size();

        return (size+1)/2;
    }
};