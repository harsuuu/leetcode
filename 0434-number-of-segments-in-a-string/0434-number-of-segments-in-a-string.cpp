class Solution {
public:
    int countSegments(string s) {
        //First tokenize it
        stringstream ss(s);
        string word;
        int cnt=0;
        // then extract each word and count them
        while (ss>>word) {
            cnt++;
        }
    return cnt;
    }
};