class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {

        int total = 0;
        for (auto it : arr) {
            total += it;
        }

        if (total % 3 != 0) {
            return false;
        }
        int main = total / 3;

        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == main) {
                cnt++;
                sum = 0;
            }
        }
        if (cnt >= 3) {
            return true;
        }
        return false;
    }
};