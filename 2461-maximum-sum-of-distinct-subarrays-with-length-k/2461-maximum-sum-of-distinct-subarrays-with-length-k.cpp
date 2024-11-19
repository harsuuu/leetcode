class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return 0; 

        long long sum = 0, maxSum = 0;
        unordered_set<int>mpp;

        // Sliding window
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                sum -= nums[i - k];
                mpp.erase(nums[i - k]);
            }
            
            sum += nums[i];
            mpp.insert(nums[i]);

            if (mpp.size() == k && i >= k - 1) {
                maxSum = max(maxSum, sum);
            }
        }
    return maxSum;
    }
};