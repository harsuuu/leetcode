class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k!=0)      return false;

        map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }

        while(!mp.empty()){
            int a = mp.begin()->first;
            for(int j=0;j<k;j++){
                if(mp.find(a+j) == mp.end()) return false;
                else{
                    mp[a+j]--;
                }

                if(mp[a+j]<1)
                {
                    mp.erase(a+j);
                }
            }
        }
        return true;
    }
};