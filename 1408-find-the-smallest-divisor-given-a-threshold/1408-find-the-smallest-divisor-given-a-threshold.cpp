class Solution {
public:
    int findmax(vector<int>&nums)
    {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(nums[i],maxi);
        }
    return maxi;
    }
    int divide(vector<int>& nums,int k)
    {
        int total=0;
        for(int i=0;i<nums.size();i++)
        {
            total+=ceil((double)nums[i]/(double)k);
        }
    return total;
    }
int smallestDivisor(vector<int>& nums, int threshold) {
 int maxi = findmax(nums);
	int low=1;
	int ans=0;
	int high=maxi;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(divide(nums,mid)<=threshold)
		{
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
return ans;
}
};