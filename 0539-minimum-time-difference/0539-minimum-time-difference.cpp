class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int>mintues;
        for(int i=0;i<n;i++)
        {
            string curr = timePoints[i];
            int hour = stoi(curr.substr(0,2));
            hour = (hour == 0) ? 24 : hour;
            int min = stoi(curr.substr(3,2));
            mintues.push_back(hour*60+min);
        }

        sort(mintues.begin(),mintues.end());

        int k = mintues.size();
        int mini = INT_MAX;
        for(int i=0;i<k-1;i++)
        {
            int diff =mintues[i+1]-mintues[i];
            mini=min(mini,diff);
        }

    return mini;
    }
};