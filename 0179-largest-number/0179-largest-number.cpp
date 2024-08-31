class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto myCustom= [](int &a, int &b)
        {
            string s1=to_string(a);
            string s2=to_string(b);

            if((s1+s2) > (s2+s1))
            {
                return true;
            }
            else{
                return false;
            }
        };
        sort(nums.begin(),nums.end(),myCustom);

        if(nums[0]==0)  return "0";

        string num =""; 
        for(auto it:nums)
        {
            num+=to_string(it);
        }

    return num;
    }
};