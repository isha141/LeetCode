class Solution {  
    int mod=(int)1e9+7;
    private:
    int solve(int i,int n,vector<int>&dp){
        if(i>n) return 0;
        int take=0;
        int not_take=0;
        if(dp[i]!=-1)
            return dp[i];
        take=1+solve(i+2,n,dp);
        not_take=solve(i+1,n,dp);
        return dp[i]=(take+not_take)%mod;
    }
public:
    int countHousePlacements(int n) { 
        vector<int>dp(n+1,-1);
        long long ans=solve(1,n,dp)+1;
        return (ans%mod*ans%mod)%mod;
    }
};