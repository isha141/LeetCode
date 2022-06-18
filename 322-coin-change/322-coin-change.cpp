class Solution {  
    private:
    int solve(int n,vector<int>&coins,int amount,vector<vector<int>>&dp){
       if(amount<0)
            return 1e9;
        if(n==0){
            if(amount%coins[0]==0) 
                return amount/coins[0];
            return 1e9;
            
         } 
        if(dp[n][amount]!=-1) return dp[n][amount];
        int pick=solve(n,coins,amount-coins[n],dp)+1;
        int not_pick=solve(n-1,coins,amount,dp); 
        return dp[n][amount]=min(pick,not_pick); 
        
    }
public:
    int coinChange(vector<int>& coins, int amount) { 
        int n=coins.size(); 
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       int ans= solve(n-1,coins,amount,dp);
      if(ans==1e9) return -1;
        else
            return ans;
    }
};