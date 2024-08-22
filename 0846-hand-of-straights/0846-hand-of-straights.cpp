class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        for(auto i:hand)
            mp[i]++;

        while(mp.empty()!=true){
            int a = mp.begin()->first;
            for(int j=0;j<groupSize;j++){
                if(mp.find(a+j) == mp.end()) return false;
                else{
                    if(mp[a+j]>0){
                        mp[a+j]--;
                        if(mp[a+j]==0) mp.erase(a+j);
                    }
                }
            }
        }
        return true;
    }
};