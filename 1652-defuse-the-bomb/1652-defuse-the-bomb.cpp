class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k==0){
            vector<int>ans(n, 0);
            return ans;
        }
        int K = k;
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(k > 0){
                int ind = i+1;
                long long sum = 0;
                while(k--){
                    sum += code[ind%n];
                    ind++;
                }
                ans.push_back(sum);
            }
            else if(k < 0){
                int ind = i-1;
                long long sum = 0;
                k = abs(k);
                while(k--){
                    sum += code[(ind%n + n)%n];
                    ind--;
                }
                ans.push_back(sum);
            }
            k = K;
        }
        return ans;
    }
};