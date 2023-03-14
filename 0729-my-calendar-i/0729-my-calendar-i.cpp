class MyCalendar { 
  vector<pair<int,int>>ds;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) { 
           for(auto itr: ds){
               if(start<itr.first && end>itr.first)
                     return 0;
               if(start>=itr.first && start<itr.second) return 0;
               // if(start<itr.second && start>=itr.first) return 0;
           }
        ds.push_back({start,end}); 
        sort(ds.begin(),ds.end());
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */