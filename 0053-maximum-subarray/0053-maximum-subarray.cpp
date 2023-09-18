class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadane's algorithm 
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
        //Step :1
            sum=sum+nums[i];
        //Step :2
            maxi=max(sum,maxi);    
        //Step :3
            if(sum<0)
            {
                sum=0;
            }
        }return maxi;
    }
};