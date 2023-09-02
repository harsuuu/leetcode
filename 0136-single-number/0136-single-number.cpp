class Solution {
public:
    int singleNumber(vector<int>& nums) {
    //if array is [2,2,1] then output is 1.
    //if we will do xor operation of all element then it will be like 2^2^1 then result will 0^1 and zero ^ Number == Number .
    int xorr = 0;
    for( int i=0; i< nums.size(); i++ )
    {
        xorr = xorr^nums[i];
    }
    return xorr;
    }
};