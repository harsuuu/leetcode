class MyCalendar {
public:
    vector<pair<int,int>>range;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto x:range)
        {
            int st=x.first;
            int en=x.second;
            if(st<end && en>start) return false;
            
        }
        range.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */