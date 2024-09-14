class Solution {
public:
    int minCut(string s) {
    int n = s.length();
    
    // Step 1: Create a table to store palindrome information
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    
    // Step 2: Precompute all palindromes
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i <= 2 || isPalindrome[i + 1][j - 1])) {
                isPalindrome[i][j] = true;
            }
        }
    }

    // Step 3: Create a dp array to store the minimum cuts
    vector<int> dp(n + 1, 0);
    dp[n] = 0;  // No cuts needed for an empty string

    // Step 4: Fill dp array using the precomputed palindrome table
    for (int i = n - 1; i >= 0; i--) {
        int mini = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome[i][j]) {
                int cost = 1 + dp[j + 1];
                mini = min(mini, cost);
            }
        }
        dp[i] = mini;
    }
    
    return dp[0] - 1;  // Subtract 1 because we want the number of cuts, not partitions
}
};