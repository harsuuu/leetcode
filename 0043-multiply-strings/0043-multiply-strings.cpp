class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size();
        int n = num2.size();
        vector<int> result(m + n, 0);

        // Multiply each digit and add to the result array
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;      //carry 
            }
        }

        // Convert result array to string
        string resultStr;
        for (int num : result) {
            if (!(resultStr.empty() && num == 0)) { // Skip leading zeros
                resultStr.push_back(num + '0');
            }
        }

        return resultStr.empty() ? "0" : resultStr;
    }
};