class MedianFinder {
public:
    vector<int>ans;
    MedianFinder() {
        ans.clear();
    }
    
    void addNum(int num) {
        ans.push_back(num);
    }
    
    double findMedian() {
        sort(ans.begin(),ans.end());
        int n = ans.size();
        if(n%2==0)
        {
            return (ans[n / 2 - 1] + ans[n / 2]) / 2.0;
        }
        else{
            return ans[n/2.0];
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */