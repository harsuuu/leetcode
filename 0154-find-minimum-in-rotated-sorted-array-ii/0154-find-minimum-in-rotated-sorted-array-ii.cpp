class Solution {
public:
    int findMin(vector<int>& nums) {
        int low =0;
        int high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==nums[low] && nums[mid]==nums[high])
            {
                low++;
                high--;
                ans=min(ans,nums[mid]);
                continue;
            }
            //Identify the sorted array.
            if(nums[mid]<=nums[high]) //right half is sorted
            {
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
            else //left half is sorted
            {
                ans=min(ans,nums[low]);
                low=mid+1;
            }
        }
        return ans;
    }
};