class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3)   return false;

        bool foundPeak = false;

        for(int i=1;i<arr.size()-1;i++)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                foundPeak = true;  // Found a peak
            }
            if (arr[i] <= arr[i - 1]  || arr[i] <= arr[i + 1]) {
                return false;
            }
        }
    return foundPeak;
    }
};