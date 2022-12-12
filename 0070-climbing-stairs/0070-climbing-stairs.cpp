int dp[46];
class Solution {
    int solve(int i){
        if(i==0)
            return 1;
        if(i<=0)
            return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=solve(i-2)+solve(i-1);
    }
public:
    int climbStairs(int n) {
        if(n==0 || n==1)
            return n;
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};