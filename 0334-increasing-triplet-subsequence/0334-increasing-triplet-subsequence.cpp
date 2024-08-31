class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;  // Not enough elements to form a triplet

        int first = INT_MAX;   // Initialize the smallest element to maximum possible
        int second = INT_MAX;  // Initialize the second smallest element to maximum possible

        for (int i = 0; i < n; i++) {
            if (arr[i] <= first) {
            // Update the smallest element
            first = arr[i];
        } else if (arr[i] <= second) {
            // Update the second smallest element
            second = arr[i];
        } else {
            // Found a valid triplet (first < second < arr[i])
            return true;
        }
    }

    // No valid triplet found
    return false;
    }
};