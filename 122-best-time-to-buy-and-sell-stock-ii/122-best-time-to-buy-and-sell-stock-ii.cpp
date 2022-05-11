class Solution { 
    private:
    long solve(int ind,int n,int buy, vector<vector<int>>&dp,vector<int>& prices)
    {
        if(ind==n)
            return 0;
        long profit=0;
        long profit2=0; 
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        if(buy)
           dp[ind][buy]=max((-prices[ind]+ solve(ind+1,n,!buy,dp,prices)),0+solve(ind+1,n,buy,dp,prices)); 
        else
          dp[ind][buy]= max((prices[ind]+ solve(ind+1,n,!buy,dp,prices)),0+solve(ind+1,n,buy,dp,prices));  
         return dp[ind][buy];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(); 
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int buy=1;
        return solve(0,n,buy,dp,prices);
        
        
    }
};