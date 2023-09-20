class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        //o(n)
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] != nums[start])
            {
                start++;
                nums[start] = nums[i];
            }
        }
        return start+1;
    }
};