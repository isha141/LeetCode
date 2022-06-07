class Solution { 
    private:
    long solve(int i,int j,vector<vector<int>>& grid,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1)
        {
            return grid[i][j];
        } 
        if(i>=m || j>=n)
            return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        long  left=0;
        left=grid[i][j]+solve(i+1,j,grid,m,n,dp);
        long right=grid[i][j]+solve(i,j+1,grid,m,n,dp);
        return dp[i][j]=min(left,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) { 
        int m=grid.size();
        int n=grid[0].size(); 
        vector<vector<int>>dp(m,vector<int>(n,-1)); 
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    continue;
              int up=INT_MAX;
                int left=INT_MAX;
                if(i-1>=0)
                   up=dp[i-1][j];
                if(j-1>=0)
                    left=dp[i][j-1];
                dp[i][j]=min(up,left)+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};