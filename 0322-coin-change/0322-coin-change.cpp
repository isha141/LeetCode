class Solution { 
    private:
    int solve(int i,int amount,int n,vector<int>&coins,vector<vector<int>>&dp){
        if(i>=n)
            return 1e9;
        if(amount==0)
            return 0;
        if(amount<=0)
            return 1e9;
        int pick=0;
        int not_pick=0; 
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        pick=1+solve(i,amount-coins[i],n,coins,dp);
        not_pick=solve(i+1,amount,n,coins,dp);
        return dp[i][amount]=min(pick,not_pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans=0; 
        sort(coins.rbegin(),coins.rend()); 
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int temp=solve(0,amount,n,coins,dp); 
        return temp>=1e9?-1:temp;
    }
};