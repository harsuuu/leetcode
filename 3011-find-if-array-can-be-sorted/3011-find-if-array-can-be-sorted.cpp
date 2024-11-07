class Solution {
public:
    bool canSortArray(vector<int>& nums) {
         int n = nums.size();

        bool swapped = true;

        for(int i = 0; i < n; i++) {
            swapped = false;

            for(int j = 0; j < n - i - 1; j++) { //in every pass, the max element bubbles up to right most index
                if(nums[j] <= nums[j+1]) { //no swap required
                    continue;
                } else { //pakka nums[j] > nums[j+1]
                    //swap is required
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])) {
                        swap(nums[j], nums[j+1]);
                        swapped = true;
                    } else {
                        //not able to swap, hence can't sort it
                        return false;
                    }
                }
            }

            if(swapped == false) { //no swapping was done in the pass, hence array was already sorted
                break; //no more passes are required
            }

        }

        return true;
    }
};