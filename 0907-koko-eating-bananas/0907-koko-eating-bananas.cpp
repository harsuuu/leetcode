class Solution {
public:
    int findmax(vector<int>& piles)
    {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            maxi=max(piles[i],maxi);
        }
        return maxi;
    }
    long long requireTime(vector<int>& piles,int hour)
    {
        long long totalHour=0;
        for(int i=0;i<piles.size();i++)
        {
            totalHour+=ceil((double) piles[i] / (double)hour);
        }
    return totalHour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      
    int maxi=findmax(piles);
    int ans=0;
    int low=1;
    int high=maxi;
    while(low<=high)
    {
        int mid=(low+high)/2;

        long long totalTime=requireTime(piles,mid);
        if(totalTime<=h)
        {
            high=mid-1;
            ans=mid;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
    }
};