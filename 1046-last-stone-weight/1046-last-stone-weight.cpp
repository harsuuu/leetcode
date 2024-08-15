class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)
        {
            return stones[0];
        }
        priority_queue<int>pq;
        for(auto it:stones)
        {
            pq.push(it);
        }
        while(pq.size()>1)
        {
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();

            if(x==y)
            {
                continue;
            } 
            else if(x!=y)
            {
                int temp = abs(y-x);
                pq.push(temp);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};