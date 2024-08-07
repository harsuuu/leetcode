class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> oddValues;
        vector<int> evenValues;

        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                evenValues.push_back(nums[i]);
            }    
            else {
                oddValues.push_back(nums[i]);
            }
        }
    
    // Sort the values
    sort(evenValues.begin(), evenValues.end());  // non-decreasing order
    sort(oddValues.begin(), oddValues.end(), greater<int>());  // non-increasing order
    
    // Merge back into nums
    int evenIndex = 0;
    int oddIndex = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i % 2 == 0) {
            nums[i] = evenValues[evenIndex++];
        } else {
            nums[i] = oddValues[oddIndex++];
        }
    }
    
    return nums;
    }
};