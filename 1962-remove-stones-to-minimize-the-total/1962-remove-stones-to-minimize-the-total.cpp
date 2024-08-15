class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>maxHeap;
        for(auto it:piles)
        {
            maxHeap.push(it);
        }

        while(k)
        {
            auto it = maxHeap.top();
            maxHeap.pop();
            k--;
            it = it - floor(it/2);
            maxHeap.push(it);
        }
        int sum=0;
        while(!maxHeap.empty())
        {
            sum+=maxHeap.top();
            maxHeap.pop();
        }

    return sum;
    }
};