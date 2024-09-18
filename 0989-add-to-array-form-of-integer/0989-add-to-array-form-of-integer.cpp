class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int carry = k;

    // Process each digit from the end of the vector `num`
    for (int i = num.size() - 1; i >= 0 || carry > 0; --i) {
        if (i >= 0) {
            carry += num[i];
        }
        result.push_back(carry % 10);
        carry /= 10;
    }

    // Reverse the result to get the correct order
    reverse(result.begin(), result.end());
    return result;
    }
};