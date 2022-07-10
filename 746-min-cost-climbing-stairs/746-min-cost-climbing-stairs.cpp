class Solution {
    private:
    int solve(int ind,vector<int>&cost,int n,vector<int>&dp){
        if(ind>=n)
            return 0;
        // if(ind==n-1) 
            // return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take=INT_MAX;
        int not_take=INT_MAX;
        take=cost[ind]+min(solve(ind+1,cost,n,dp),solve(ind+2,cost,n,dp));
       return dp[ind]= take;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size(); 
        vector<int>dp(n,-1);
        return min(solve(0,cost,n,dp),solve(1,cost,n,dp)); 
    }
};