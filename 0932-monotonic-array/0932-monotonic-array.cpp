class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
    bool flag=false;
    bool flag1=false;
    for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                flag = true;
            } else if (nums[i] < nums[i - 1]) {
                flag1 = true;
            }
            if (flag && flag1) {
                return false; 
            }
        }
        return true; 
    }
};