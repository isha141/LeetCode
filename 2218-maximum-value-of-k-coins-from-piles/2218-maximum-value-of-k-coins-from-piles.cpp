class Solution { 
    private:
    int n;
    int solve(int i,vector<vector<int>>&p,int k,vector<vector<int>>&dp){
        if(i>=n || k<=0) 
            return 0; 
        if(dp[i][k]!=-1) 
            return dp[i][k];
        int res=solve(i+1,p,k,dp);
        int cur=0;
        for(int j=0;j<p[i].size() && j<k;++j){
            cur+=p[i][j];
            res=max(res,cur+solve(i+1,p,k-j-1,dp)); 
            // res=max(res,cur);
        } 
        dp[i][k]=res;
        return res;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
         n=p.size(); 
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(0,p,k,dp);
    }
};