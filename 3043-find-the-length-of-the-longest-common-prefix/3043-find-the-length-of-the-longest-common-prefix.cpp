class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(auto it:arr1)
        {
            while(it>0)
            {
                st.insert(it);

                it=it/10;
            }
        }

        int ans=0;
        for (auto num : arr2) {
            while (num > 0) {
                if (st.find(num) != st.end()) {
                // Calculate the length of the common prefix
                int length = static_cast<int>(log10(num)) + 1;
                ans = max(ans, length);
                break;
            }
            num /= 10;
        }
    }

    return ans;
    }
};