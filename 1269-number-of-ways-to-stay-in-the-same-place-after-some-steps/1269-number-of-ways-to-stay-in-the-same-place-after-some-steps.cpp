
class Solution {
    private:
    int mod=1e9+7;
    int solve(int i,int steps,int len,vector<vector<long long>>&dp){
         if(steps==0){
              if(i==0)
                    return 1;
             return 0;
         } 
          // cout<<i<<"-->"<<steps<<endl;
          if(i<0) return 0;
          if(i>=len) return 0;
          if(steps<=0) return 0;
          if(dp[i][steps]!=-1) 
              return dp[i][steps];
         long long left=solve(i-1,steps-1,len,dp)%mod;
         long long right=solve(i+1,steps-1,len,dp)%mod;
         long long stay=solve(i,steps-1,len,dp)%mod;
         return dp[i][steps]=(left%mod + right%mod + stay%mod)%mod;
    }
public:
    int numWays(int steps, int len) {
        vector<vector<long long>>dp(steps+1,vector<long long>(steps+2,-1));
        return solve(0,steps,len,dp);
    }
};