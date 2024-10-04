class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size(); 
        sort(skill.begin(),skill.end());

        if(n==2)     return skill[0]*skill[1];

        vector<pair<int,int>>vec;
        int i=0;
        int j=n-1;

        while(i<n/2){
            vec.push_back({skill[i],skill[j]});
            i++;
            j--;
        }
        int total=0;
        int sum = vec[0].first + vec[0].second; 
        for(int i=0;i<vec.size();i++)
        {
            auto a = vec[i];
            if ((a.first + a.second) != sum) { 
                return -1;
            }
            total += a.first * a.second; 
        }
    return total;
    }
};