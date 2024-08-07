class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>temp(nums.size());
        int e=0;
        int o=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                temp[e]=(nums[i]);
                e=e+2;
            }
            else{
                temp[o]=(nums[i]);
                o=o+2;
            }
        }
    return temp;
    }
};