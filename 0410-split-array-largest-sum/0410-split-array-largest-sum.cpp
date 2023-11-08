class Solution {
public:
    int countStudent(vector<int>&arr,int pages)
{
    int student=1;
    long long pageC=0;
    for(int i=0;i<arr.size();i++)
    {
        if(pageC+arr[i]<=pages)
        {
            pageC+=arr[i];
        }
        else{
            student++;
            pageC=arr[i];
        }
    }
return student;
}
int findPages(vector<int>& arr, int n, int m) {

    //Base condition 
    if(m>n) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(), arr.end(), 0);

 while(low<=high)
    {
        int mid=(low+high)/2;
        int student=countStudent(arr,mid);
        if(student>m)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
            
        }
    }
    return low;   
}
    int splitArray(vector<int>& nums, int k) {
     int n=nums.size();
     return findPages(nums,n,k);
    }
};