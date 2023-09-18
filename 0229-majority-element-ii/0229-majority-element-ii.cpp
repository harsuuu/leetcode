class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int element1, element2;
        for(int i=0;i<nums.size();i++)
        {
            if(count1==0 && element2!=nums[i])
            {
                count1=1;
                element1=nums[i];
            }
            else if(count2==0 && element1!=nums[i])
            {
                count2=1;
                element2=nums[i];
            }
            else if(nums[i]==element1)
            {
                count1++;
            }
            else if(nums[i]==element2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        int c1=0;
        int c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(element1==nums[i]) c1++;
            if(element2==nums[i]) c2++;
        }
        int min=nums.size()/3;
        vector<int>ans;
        if(c1>min)
        {
            ans.push_back(element1);
        }
        if(c2>min)
        {
            ans.push_back(element2);
        }return ans;
    }
};