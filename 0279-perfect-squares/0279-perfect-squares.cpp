class Solution { 
    private:
    int solve(int n,int sum,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(n<0){
            return 1e9;
        }
        if(dp[n]!=-1)
            return dp[n];
        int ans=1e9;
        for(int i=1;i*i<=n;++i){
            int temp=1+solve(n-(i*i),sum,dp);
            ans=min(ans,temp);
        }
        return dp[n]=ans;
    }
public:
    int numSquares(int n) {
        if(n==0 || n==1) return n;
        int ans=1e9;
        vector<int>dp(n+1,-1);
         return solve(n,n,dp);
    }
};