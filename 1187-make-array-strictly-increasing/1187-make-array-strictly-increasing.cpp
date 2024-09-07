class Solution {
public: 
    map<pair<int,int>,int>mpp;
    int solve(int i,vector<int>& arr1, vector<int>& arr2,int prev)
    {
        //base case
        if(i>=arr1.size())  return 0;

        if(mpp.find({i,prev})!=mpp.end())
        {
            return mpp[{i,prev}];
        }
        //Step 1: 1 condition
        int result1 = 1e9+1;
        if(arr1[i]>prev)
        {
            result1 = solve(i+1,arr1,arr2,arr1[i]);
        }
        //Step 2: 2 condition
        int result2 = 1e9+1;
        int ub = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if (ub < arr2.size()) {
            result2 = 1 + solve(i + 1, arr1, arr2, arr2[ub]);
        }
    //Step 3:min(1 condition, 2 condition)
    return mpp[{i,prev}] = min(result1,result2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        mpp.clear();
        sort(arr2.begin(),arr2.end());
        int ans = solve(0,arr1,arr2,-1);
        
        if(ans==1e9+1)  return -1;
    return ans;
    }
};