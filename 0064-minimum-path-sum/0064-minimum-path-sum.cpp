class Solution {
    private: 
    int n,m; 
 
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i<0 || i>=n || j<0 || j>=m ) return 1e9;
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1) 
            return dp[i][j];
        int down=grid[i][j]+solve(i+1,j,grid,dp);
        int right=grid[i][j]+solve(i,j+1,grid,dp); 
        return dp[i][j]=min(down,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
            n=grid.size();
            m=grid[0].size();
            vector<vector<int>>dp(n,vector<int>(m,-1));
            return solve(0,0,grid,dp);
    }
};