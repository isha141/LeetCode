int dp[1001][101][2];
class Solution {
    private:
    int n;
    int solve(int i,vector<int>&prices,int k,bool flag){
          if(i>=n){
              if(flag==0) 
                  return 0;
              return -1e9;
         }
        if(k==0)
             return 0;
        if(dp[i][k][flag]!=-1)
              return dp[i][k][flag];
        int buy=0;
        int sell=0;
        if(flag==0){
            buy=max(-prices[i]+solve(i+1,prices,k,!flag),solve(i+1,prices,k,flag));
        } 
        else
        sell=max(prices[i]+solve(i+1,prices,k-1,!flag),solve(i+1,prices,k,flag));
        return dp[i][k][flag]=max(buy,sell);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;--i){
            for(int buy=0;buy<=1;++buy){
                for(int j=1;j<=k;++j){
                    if(buy==0){
                        dp[i][buy][j]=max(-prices[i]+dp[i+1][1][j],dp[i+1][0][j]);
                    }
                    else{
                        dp[i][buy][j]=max(prices[i]+dp[i+1][0][j-1],dp[i+1][1][j]);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};