class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int size=INT_MAX;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){  
                sum += nums[j];
                if (sum >= target) {  
                    size = min(size, j - i + 1); 
                    break;  //inner loop will stop
                }
        }
    }
    return size==(INT_MAX) ? 0 : size;
    
    }
};