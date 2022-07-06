class StockSpanner { 
    stack<pair<int,int>>q;
public:
    StockSpanner() {
        
    }
    int next(int price) { 
        int count=0;
      while(!q.empty() && q.top().first<=price){ 
          count+=q.top().second;
          q.pop();
      }
      q.push({price,count+1});
        return count+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */