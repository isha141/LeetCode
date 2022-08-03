class MyCalendar { 
    private:
    vector<pair<int,int>>v;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto itr: v){
            if((end>itr.first && start<itr.second))
                return 0;
        }
        v.push_back({start,end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */