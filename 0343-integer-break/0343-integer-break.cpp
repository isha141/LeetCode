 int dp[60];
class Solution { 
    private:
    // int ans=0;
    int solve(int n){
        if(n<=3)
              return n;
        if(dp[n]!=-1)
              return dp[n];
        int ans=0;
        for(int j=2;j<=n;++j){
            ans=max(ans,j*solve(n-j));
        }
        
        return dp[n]=ans;
    }
public:
    int integerBreak(int n) {
        if(n<=3)
              return n-1;
         memset(dp,-1,sizeof(dp));
         return solve(n); 
          // return ans;
    }
};