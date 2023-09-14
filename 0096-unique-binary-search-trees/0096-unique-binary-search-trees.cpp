int dp[20];
class Solution {
    private:
    int solve(int n){
        if(n<0)
              return 0;
        if(n==0 || n==1)
              return 1;
        if(dp[n]!=-1)
              return dp[n];
        long long ans=0;
         for(int i=1;i<=n;++i){
             ans+=solve(i-1)*solve(n-i);
         }
        return dp[n]=ans;
    }
public:
    int numTrees(int n) { 
         memset(dp,-1,sizeof(dp));
          return solve(n);
    }    
};