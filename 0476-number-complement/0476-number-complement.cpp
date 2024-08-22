class Solution {
public:
    int findComplement(int num) {
        //Basically jo bhi num hai usme jitne bit hai utne hi 1 bit lekr xor krdo.

        int numBits = (int)(log2(num)) + 1;
        
        // Create a mask with all bits set to 1 that are of the same length as num
        unsigned int mask = (1U << numBits) - 1; //unsigned taken to avoid integer overflow

        return num ^ mask;
    }
};