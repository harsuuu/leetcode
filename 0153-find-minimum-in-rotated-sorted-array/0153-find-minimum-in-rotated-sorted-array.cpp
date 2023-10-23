class Solution {
public:
    int findMin(vector<int>&arr) {
       int n=arr.size();
       int low=0;
       int high=n-1;
       int ans=INT_MAX;
       while(low<=high)
       {
           int mid=(low+high)/2;
           //for better time complexity
           if(arr[low]<=arr[high])
           {
               ans=min(arr[low],ans);
               break;
           }
           if(arr[mid]>=arr[low])
           {
               ans=min(arr[low],ans);
               low=mid+1;
           }
           else
           {
               ans=min(arr[mid],ans);
               high=mid-1;
           }
       }
    return ans;
    }
};