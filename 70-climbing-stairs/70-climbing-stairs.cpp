class Solution { 
    private:
    int count(int n,vector<int>&dp)
    {
        if(n<=1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=count(n-1,dp)+ count(n-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return count(n,dp);
    }
};