class Solution { 
    private:
    int solve(int i,int j,int m,vector<vector<int>>& t,vector<vector<int>>&dp){
        if(i==m-1)
            return t[i][j]; 
      //  if(i>=m || j>=t[i].size()+1) return INT_MAX; 
        if(dp[i][j]!=-1) return dp[i][j];
        int left=t[i][j]+solve(i+1,j,m,t,dp);
        int right=t[i][j]+solve(i+1,j+1,m,t,dp);
        return dp[i][j]=min(left,right);
        
    }
public:
    int minimumTotal(vector<vector<int>>& t) {
       int m =t.size();
       vector<vector<int>>dp(m,vector<int>(m,-1));
        return solve(0,0,m,t,dp);
    }
};