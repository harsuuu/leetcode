class Solution {
public:
    int findmax(vector<int>& weights)
    {
        int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++)
        {
            maxi=max(weights[i],maxi);
        }
    return maxi;
    }
    int findsum(vector<int>& weights)
    {
        int sum=0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
        }
    return sum;
    }

    int daysRequired(vector<int>& weights,int capacity)
    {
        int day=1;
        int load=0;
        for(int i=0;i<weights.size();i++)
        {
            if(load+weights[i]>capacity)
            {
                day=day+1;
                load=weights[i];
            }
            else
            {
                load+=weights[i];
            }
        }
    return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=findmax(weights);
        int sum=findsum(weights);
        int ans=0;
        int low=maxi;
        int high=sum;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(daysRequired(weights,mid)<=days)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
    return ans;
    }
};