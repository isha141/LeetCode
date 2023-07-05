class Solution { 
    private:
    int n;
    int solve(int i,vector<int>&p,bool flag,vector<vector<int>>&dp){
        if(i>=n){
            if(flag)
                return -1e9;
            return 0;
        }  
        int pick=0; 
        int not_pick=0; 
        if(dp[i][flag]!=-1) return dp[i][flag];
        if(!flag){
        pick=max(-p[i]+solve(i+1,p,!flag,dp),solve(i+1,p,flag,dp));
        }
        else{
        not_pick=max(p[i]+solve(i+1,p,!flag,dp),solve(i+1,p,flag,dp)); 
        }
        return dp[i][flag]=max(pick,not_pick);
    }
public:
    int maxProfit(vector<int>& p) {
          n=p.size(); 
        vector<vector<int>>dp(n,vector<int>(2,-1));
          return solve(0,p,0,dp);
    }
};