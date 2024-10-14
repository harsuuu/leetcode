class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long score = 0;
    
        while (k-- && !pq.empty()) {
            int a = pq.top();
            pq.pop();
            score += a;
            
            // Push the adjusted value back into the priority queue if it is greater than zero
            int value = ceil(static_cast<double>(a) / 3);
            if (value > 0) {
                pq.push(value);
            }
    }
    
    return score;
    }
};