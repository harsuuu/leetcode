class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
    string ans = "";
    priority_queue<pair<int, char>> pq;
    
    if (a > 0) pq.push({a, 'a'});
    if (b > 0) pq.push({b, 'b'});
    if (c > 0) pq.push({c, 'c'});
    
    while (pq.size() > 1) {
        auto top1 = pq.top();
        pq.pop();
        auto top2 = pq.top();
        pq.pop();

        // Add two characters from the highest frequency if possible
        if (top1.first >= 2) {
            ans += top1.second;
            ans += top1.second;
            top1.first -= 2;
        } else {
            ans += top1.second;
            top1.first -= 1;
        }

        // Add back the remaining count to the priority queue
        if (top1.first > 0) {
            pq.push(top1);
        }

        // Add one or two characters from the second highest frequency if possible
        if (top2.first >= 2 && top2.first >= top1.first) {
            ans += top2.second;
            ans += top2.second;
            top2.first -= 2;
        } else {
            ans += top2.second;
            top2.first -= 1;
        }

        // Add back the remaining count to the priority queue
        if (top2.first > 0) {
            pq.push(top2);
        }
    }

    // If there's one character type left in the priority queue
    if (!pq.empty()) {
        auto top = pq.top();
        if (top.first >= 2) {
            ans += top.second;
            ans += top.second;
        } else {
            ans += top.second;
        }
    }
    
    return ans;
    }
};