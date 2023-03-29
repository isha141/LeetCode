class Solution {
    private: 
    int n; 
    int ans=0;
    int solve(int ind,vector<int>&sat,int c,vector<vector<int>>&dp){
        if(ind>=n)
            return 0; 
        if(dp[ind][c]!=-1) 
            return dp[ind][c];
        int take=0;
        int not_take=0;
        take=sat[ind]*c+solve(ind+1,sat,c+1,dp);
        not_take=solve(ind+1,sat,c,dp);
        ans=max(take,not_take);
        return dp[ind][c]=max(take,not_take);
    }
public:
    int maxSatisfaction(vector<int>& sat) {
          n=sat.size(); 
          sort(sat.begin(),sat.end()); 
          vector<vector<int>>dp(n,vector<int>(n+1,-1));
           return solve(0,sat,1,dp);
          // return ans;
    }
};