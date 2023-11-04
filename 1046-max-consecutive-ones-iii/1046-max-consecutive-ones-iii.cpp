class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flip=0;
        int ans=0;
        int i=0;    //for move forwarding
        int j=0;    //for unflipping the 1 to 0 if required.
        int n=nums.size();
        while(i<n)
        {
            if(nums[i]==0)
            {
                flip++;
            }
            while(flip>k)
            {
                //ab tumne phle jo kra the 0 ka 1 usme se jo sbse phle kra tha use dubara se 1 to 0 kr do.
                if(nums[j]==0)
                {
                    flip--;
                }
                j++;
            }
            ans=max(ans,i-j+1);
            i++;    //i ko increment krte rho qki ye iterate kr rhi hai.
        }
    return ans;
    }
};