int dp[100001][2][3]={-1};
class Solution { 
    int solve(int ind,vector<int>&prices,int count,int buy,int n,vector<vector<vector<int>>>&dp)
    {
        if(ind>=n)
            return 0; 
        if(count==0) return 0;
        int maxi=-1e9; 
        if(dp[ind][buy][count]!=-1)
            return dp[ind][buy][count]; 
        // if(count<=2){
        if(buy)
         return  dp[ind][buy][count]=max(-prices[ind]+solve(ind+1,prices,count,!buy,n,dp),solve(ind+1,prices,count,buy,n,dp)); 
           return dp[ind][buy][count]=max(prices[ind]+solve(ind+1,prices,count-1,!buy,n,dp),solve(ind+1,prices,count,buy,n,dp));
            // dp[ind][buy][count]=maxi;
        // }
        // return dp[ind][buy][count];
    }
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int n=prices.size();
        int count=2;
        int buy=1;   
        int not_buy=0; 
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,prices,count,buy,n,dp);
    }
};