class Solution { 
    private:
    int solve(int n,vector<int>&coins,int amount,vector<vector<int>>&dp){  
          if(amount<0) return 0;
        if(amount==0) return 1;
        if(n==0){
            return (amount%coins[0]==0);
        } 
        if(dp[n][amount]!=-1) return dp[n][amount];
        int left=solve(n,coins,amount-coins[n],dp);
        int right=solve(n-1,coins,amount,dp); 
        return dp[n][amount]=left+right;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size(); 
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp);
    }
};