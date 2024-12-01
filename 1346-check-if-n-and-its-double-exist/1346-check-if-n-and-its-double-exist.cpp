class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>st(arr.begin(), arr.end());
        int n = arr.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)   cnt++;
        }
        if (cnt > 1) return true;
        for (int i=0;i<n;i++) {
            if (arr[i]!=0 && st.find(2*arr[i]) != st.end()) {
                return true;
            }
        }
    return false;
    }
};