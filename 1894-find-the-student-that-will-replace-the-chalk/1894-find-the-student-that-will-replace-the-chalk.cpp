class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       int n = chalk.size();
    
    // Calculate the total chalk used in single iteration.
    long long totalChalk = 0;
    for (int i = 0; i < n; i++) {
        totalChalk += chalk[i];
    }
    
    // Reduce k by complete rounds to optimize the remaining chalk count
    k %= totalChalk;

    //itrate over them with new k by which TIME COMPLEXITY will be less.
    int i = 0;
    while (true) {
        k -= chalk[i];
        if (k < 0) {
            return i;  // Return the current student index if k becomes less than 0
        }
        i = (i + 1) % n;  // Move to the next student in a circular manner
    }
    
    // This line will never be reached because the loop will return once k < 0
    return -1;
    }
};