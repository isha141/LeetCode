int dp[1003][103][3];
class Solution {
    private:
    int n;
    int solve(int i,vector<int>&prices,int k, bool flag){
        if(i>=n){
            return 0;
        }
        if(k==0)
              return 0;
        if(dp[i][k][flag]!=-1)
             return dp[i][k][flag];
        int buy=0;
        int sell=0;
        if(!flag){
            buy=max(-prices[i]+solve(i+1,prices,k,!flag),solve(i+1,prices,k,flag));
        }
        else{
            sell=max(prices[i]+solve(i+1,prices,k-1,!flag),solve(i+1,prices,k,flag));
        }
        return dp[i][k][flag]=max(buy,sell);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
         n=prices.size();
         memset(dp,-1,sizeof(dp));
         return solve(0,prices,k,0);
    }
};