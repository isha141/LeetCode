class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;--i){
            for(int buy=0;buy<=1;buy++){
                for(int j=1;j<=k;++j){
                    if(buy==0){
                        dp[i][buy][j]=max(0,max(-prices[i]+dp[i+1][1][j],dp[i+1][buy][j]));
                    }
                    else{
                        dp[i][buy][j]=max(dp[i+1][buy][j],prices[i]+dp[i+1][0][j-1]);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};