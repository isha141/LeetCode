class Solution { 
    private: 
    const int ans=1e9;
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)
            return grid[0][0];
        else if(i<0 || j<0)
            return ans;  
        if(dp[i][j]!=-1)
            return dp[i][j];
        int l=grid[i][j]+solve(i-1,j,grid,dp);
        int r=grid[i][j]+solve(i,j-1,grid,dp); 
        return dp[i][j]=min(l,r);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size(); 
        vector<vector<int>>dp(m,vector<int>(n,-1));
       return solve(m-1,n-1,grid,dp);
    }
};