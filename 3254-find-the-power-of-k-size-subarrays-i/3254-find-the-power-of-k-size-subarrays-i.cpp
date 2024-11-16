class Solution {
public:
   int checkSort(vector<int>& it) {
    int n = it.size();
    for (int i = 0; i < n - 1; i++) {
        // Check if the array is strictly increasing and consecutive
        if (it[i] + 1 != it[i + 1]) { 
            return -1; 
        }
    }
    return *max_element(it.begin(), it.end());
}
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res; 
        for (int i = 0; i <= n - k; i++) {
        vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
        int ans = checkSort(subarray);
        res.push_back(ans);
    }
    return res;
    }
};