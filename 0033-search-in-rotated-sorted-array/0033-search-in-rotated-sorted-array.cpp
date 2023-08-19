class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start=0;
        int end=arr.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]==target)
            {
                return mid;
            }
            //Now check which half is sorted --> Left || right
            
            //LEFT HALF IS SOTRED
            if(arr[start]<=arr[mid])
            {
                if(arr[start]<=target && target<=arr[mid])
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
            }
            else //Right half is sorted
            {
                if(arr[mid]<=target && target<=arr[end])
                {
                    start=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};