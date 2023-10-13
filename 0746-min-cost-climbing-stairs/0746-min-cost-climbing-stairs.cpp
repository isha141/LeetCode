int dp[1003];
class Solution {
    private: 
    int n;
    int solve(int i,vector<int>&cost){
        if(i>=n)
             return 0;
        if(dp[i]!=-1)
              return dp[i];
        int ans=INT_MAX;
        ans=cost[i]+min(solve(i+1,cost),solve(i+2,cost));
        return dp[i]=ans;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
          n=cost.size();
          memset(dp,0,sizeof(dp));
          dp[0]=cost[0];
          dp[1]=cost[1];
          for(int i=2;i<n;++i){
              int take=dp[i-1]+cost[i];
              int two=dp[i-2]+cost[i];
              dp[i]=min(take,two);
          }
         return min(dp[n-1],dp[n-2]);
    }
};