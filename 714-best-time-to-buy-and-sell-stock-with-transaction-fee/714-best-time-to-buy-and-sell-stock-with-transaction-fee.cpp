class Solution { 
    private:
    int solve(int ind,vector<int>&prices,int buy,int fee,vector<vector<int>>&dp){
        if(ind>=prices.size())
            return 0; 
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy)
            return dp[ind][buy]=max(-(prices[ind]+fee)+solve(ind+1,prices,!buy,fee,dp),solve(ind+1,prices,buy,fee,dp));
        else
            return dp[ind][buy]=max(prices[ind]+ solve(ind+1,prices,!buy,fee,dp),solve(ind+1,prices,buy,fee,dp));
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size(); 
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;--i){
            dp[i][1]=max(-(prices[i]+fee)+dp[i+1][0],dp[i+1][1]);
            dp[i][0]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
        }
        return dp[0][1];
    }
};