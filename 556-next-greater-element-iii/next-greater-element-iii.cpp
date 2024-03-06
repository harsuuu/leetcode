class Solution {
public:
    int nextGreaterElement(int n) {

    //convert this num into string.   
    auto digits = to_string(n);

    // find the next permutation using stl function.
    next_permutation(begin(digits), end(digits));
    
    //convert the string into digit and store into result.
    auto res = stoll(digits);

    //check this according to given note in question and return answer.
    return (res > INT_MAX || res <= n) ? -1 : res;
    
    }   
};