class Solution {
public:
    int maximumSwap(int num) {
        string ans = to_string(num);
        int n = ans.length(); 
        for (int i = 0; i < n; i++) {
            if (ans[i] == '9') continue;
            else {
                // Find the max element from the remaining part of the string
                char b = *max_element(ans.begin() + i + 1, ans.end());
                // Only swap if the found max element is greater than the current one
                if (b > ans[i]) {
                    int maxIndex = ans.find_last_of(b);       
                    swap(ans[i], ans[maxIndex]);
                    break;
                }
            }
        }
    return stoi(ans);
    }
};