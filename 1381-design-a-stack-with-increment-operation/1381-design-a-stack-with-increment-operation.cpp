class CustomStack {
public:
    int k;
    stack<int>st;
    CustomStack(int maxSize) {
        k=maxSize;
    }
    
    void push(int x) {
        if(st.size()<k)
        {
            st.push(x);
        }
    }
    
    int pop() {
        if(st.empty())  return -1;
        else{
            int ans = st.top();
            st.pop();
        return ans;
        }
    }
    
   void increment(int k, int val) {
   vector<int> temp;

    while (!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }

    reverse(temp.begin(), temp.end());
  
    int limit = min(k, (int)temp.size());
    for (int i = 0; i < limit; i++) {
        temp[i] += val;
    }

    // Push the elements back into the stack, maintaining order
    for (int i = 0; i < temp.size(); i++) {
        st.push(temp[i]);
    }
}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */