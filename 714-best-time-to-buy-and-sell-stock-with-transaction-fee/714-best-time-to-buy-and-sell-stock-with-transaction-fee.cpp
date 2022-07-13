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
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,prices,1,fee,dp);
    }
};