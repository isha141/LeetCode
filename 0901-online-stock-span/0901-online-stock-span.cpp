class StockSpanner { 
    deque<pair<int,int>>q;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        // if(q.empty()){
        //     q.push({price,1});
        //     return 1;
        // } 
        // cout<<price<<" l";
        int c=1; 
        while(!q.empty() && (price>=q.front().first)){
            c+=q.front().second; 
            // cout<<"is";
            q.pop_front();
        }
        q.push_front({price,c}); 
        // cout<<q.front().first<<" ,"<<q.front().second<<endl;
        // cout<<price<<endl;
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */