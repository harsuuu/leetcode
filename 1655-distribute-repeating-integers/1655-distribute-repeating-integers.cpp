class Solution {
public:
    bool solve(vector<int>&count,vector<int>&quantity,int ithCustomer)
    {
        //base case
        if(ithCustomer==quantity.size())    return true;


        for(int i=0;i<count.size();i++)
        {
            if(count[i]>=quantity[ithCustomer])
            {
                count[i]-=quantity[ithCustomer];
                if(solve(count,quantity,ithCustomer+1))
                {
                    return true;
                }
                count[i]+=quantity[ithCustomer];        //backtrack.
            }
        }
    return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int>mpp;
        for(auto it:nums)
        {
            mpp[it]++;
        }
        vector<int>count;
        for(auto it:mpp)
        {
            count.push_back(it.second);
        }

        sort(quantity.rbegin(),quantity.rend());

        return solve(count,quantity,0);
    }
};