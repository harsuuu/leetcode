class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto mycustom=[](int &a,int &b)
        {
            if(a<b) return true;
            else    return false;
        };
        sort(nums.begin(),nums.end(), mycustom);
    }
};