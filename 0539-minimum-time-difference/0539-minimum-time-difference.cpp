class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();  // Declare n once
    vector<int> minutes;

    for (int i = 0; i < n; i++) {
        string curr = timePoints[i];
        int hour = stoi(curr.substr(0, 2));
        int min = stoi(curr.substr(3, 2));
       
        minutes.push_back(hour * 60 + min);
    }

    sort(minutes.begin(), minutes.end());

    int mini = INT_MAX;  // Initialize minimum difference
    for (int i = 0; i < n - 1; i++) {
        int diff = minutes[i + 1] - minutes[i];
        mini = min(mini, diff); 
    }

    // Handle the wrap-around case for the circular time difference
    int last_diff = (minutes[0] + 1440) - minutes[n - 1];
    mini = min(mini, last_diff);

    return mini;
    }
};