class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string word = "";

        for (auto it : s) {
            if (it == ' ') {
                if (!word.empty()) {    //empty nhi mtlb kuch na kuch h word m.
                    st.push(word);
                    word = "";
                }
            } else {
                word += it;
            }
        }
        // Push the last word if it's not empty.
        if (!word.empty()) {
            st.push(word);
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) {
                ans += " ";  // Add a space between words, except after the last word.
            }
        }

    return ans;
    }
};