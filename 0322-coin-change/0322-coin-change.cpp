class Solution { 
    private:
    int solve(int i,vector<int>&coins,int amount,vector<vector<int>>&dp){
          if(amount<0)
            return 1e9;
        if(i==0){
            if((amount%coins[0])==0)
                return amount/coins[0];
             return 1e9;
        } 
      
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int pick=solve(i,coins,amount-coins[i],dp)+1;
        int not_pick=solve(i-1,coins,amount,dp);
        return dp[i][amount]=min(pick,not_pick);
    }
public: 
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size(); 
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int temp=solve(n-1,coins,amount,dp); 
        return temp==1e9?-1:temp;
    }
};