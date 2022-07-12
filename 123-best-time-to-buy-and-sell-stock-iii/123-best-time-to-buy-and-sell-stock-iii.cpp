class Solution { 
    private:
    int solve(int ind,vector<int>&prices,int trans,int n,vector<vector<int>>&dp)
    {
        if(ind>=n)
            return 0;  
        if(trans==4) return 0;
        if(dp[ind][trans]!=-1) return dp[ind][trans];
        if(trans%2==0)
            return dp[ind][trans]=max(-prices[ind]+solve(ind+1,prices,trans+1,n,dp),solve(ind+1,prices,trans,n,dp)); 
        else
           return  dp[ind][trans]=max(prices[ind]+solve(ind+1,prices,trans+1,n,dp),solve(ind+1,prices,trans,n,dp));
        
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(0,prices,0,n,dp);
    }
};