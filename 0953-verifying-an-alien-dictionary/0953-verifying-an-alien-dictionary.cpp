class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
       unordered_map<char, int> mpp;
        for (int i = 0; i < order.size(); ++i) {
            mpp[order[i]] = i;
        }

        // Step 2: Define a custom comparator using the order map
        auto compare = [&mpp](const string& a, const string& b) {

            int len = min(a.size(), b.size());
            for (int i = 0; i < len; ++i) {
                if (mpp[a[i]] != mpp[b[i]]) {
                    return mpp[a[i]] < mpp[b[i]]; // Return true if a[i] should come before b[i]
                }
            }
            // If all characters are equal up to the length of the shorter word,
            // the shorter word should come first to be considered sorted.
            return a.size() <= b.size();
        };

        // Step 3: Use is_sorted with the custom comparator to check if words are sorted
        return is_sorted(words.begin(), words.end(), compare) ||
           equal(words.begin() + 1, words.end(), words.begin());
    }
};