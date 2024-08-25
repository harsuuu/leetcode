class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

    // Priority queue with a tuple: distance, and the point as a vector<int>
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    // Calculate squared distance and push into the priority queue
    for (const auto& point : points) {
        int x = point[0];
        int y = point[1];
        int dist = x * x + y * y; // Squared distance

        // Push tuple (distance, x, y) into the priority queue
        pq.push(make_tuple(dist, x, y));
    }

    // Extract the k closest points
    while (!pq.empty() && k) {
        auto [dist, x, y] = pq.top();
        pq.pop();
        ans.push_back({x, y});
        k--;
    }

    return ans;
    }
};