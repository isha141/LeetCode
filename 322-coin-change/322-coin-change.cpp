class Solution { 
    private:
    int solve(int i,vector<int>& coins,int n, int amount,vector<vector<int>>&dp)
    {
        if(i<0)
            return 1e9;
        if(amount==0)
            return 0;
        if(amount<0)
            return 1e9; 
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int pick=1e9;
        int not_pick=solve(i-1,coins,n,amount,dp);
        if(amount-coins[i]>=0)
            pick=1+solve(i,coins,n,amount-coins[i],dp);
        return dp[i][amount]= min(pick,not_pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size(); 
        sort(coins.begin(),coins.end()); 
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int temp=solve(n-1,coins,n,amount,dp); 
        return temp==1e9?-1: temp;
    }
};