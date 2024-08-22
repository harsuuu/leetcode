class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       priority_queue<int,vector<int>,greater<int>> minheap;
        for(auto it:arr){
            minheap.push(it);
        }
        unordered_map<int,int>mpp;
        int rank=1;
        while(minheap.size()!=0){
            
            int data=minheap.top();
            minheap.pop();
            if(mpp.find(data)==mpp.end()){
                //basically nhi mila.
                mpp[data]=rank;
                rank++;
            }
        }
        int n=arr.size();
        vector<int> ans(n);
        for(int i=0;i<arr.size();i++){
            ans[i]=mpp[arr[i]];
        }
        return ans;
    }
};