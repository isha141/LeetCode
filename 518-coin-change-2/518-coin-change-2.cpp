class Solution { 
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size(); 
        vector<int>prev(amount+1,0);
        for(int i=0;i<=amount;++i){
            if(i%coins[0]==0) 
                    prev[i]=1; 
        }
      for(int i=1;i<n;i++){ 
          vector<int>curr(amount+1,0);
          for(int j=0;j<=amount;++j){
              int take=0;
              if(coins[i]<=j)
                 take=curr[j-coins[i]];
              int not_take=prev[j];
              curr[j]=take+not_take;
          } 
          prev=curr;
      }
        return prev[amount];
    }
};