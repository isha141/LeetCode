class Solution {
    private:
    int n;
    int solve(int i,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(amount==0)
             return 1;
        if(i>=n) return 0; 
        if(amount<0) return 0;
        if(dp[i][amount]!=-1)
              return dp[i][amount];
        int take=solve(i,coins,amount-coins[i],dp);
        int not_take=solve(i+1,coins,amount,dp);
        return dp[i][amount]=(take+not_take);
    }
public:
    int change(int amount, vector<int>& c) { 
         n=c.size(); 
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0)); 
         // sort(c.begin(),c.end());
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        } 
        for(int i=1;i<=n;++i){
            for(int coins=1;coins<=amount;++coins){
                int take=0;
                if(c[i-1]<=coins){
                    take=dp[i][coins-c[i-1]];
                }
                int not_take=dp[i-1][coins];
                dp[i][coins]=(take+ not_take);
            }
        }
        return dp[n][amount];
        return solve(0,c,amount,dp);
    }
};