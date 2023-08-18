class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid=(s+e)/2;

    while(s<=e)
   {

    if(target==nums[mid])
    {
        return mid;       //yha mid means index number
    }
    else if(target>nums[mid])
    {
        s=mid+1;
    }
    else //(key<nums[mid])
    {
        e=mid-1;
    }
    mid=(s+e)/2;

   } 
   //ab loop bahar aa gye mtlb element nhi mila
   return -1;
}
};