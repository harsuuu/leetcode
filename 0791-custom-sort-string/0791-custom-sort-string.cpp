class Solution {
public:
    string customSortString(string order, string s) {
        
        unordered_map<char,int>mpp;
        for (int i = 0; i < order.size(); i++) {
            mpp[order[i]] = i;
        }
       // NOTE --> if any char is not present in the map, it will retain its original position after all characters from the order have been sorted.
        auto myCustom=[&mpp](char &ch1,char &ch2)
        {
            if(mpp[ch1]<mpp[ch2])
            {
                return true;
            }
            else    return false;
        };
        sort(s.begin(),s.end(),myCustom);


    return s;
    }
};