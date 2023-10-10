int dp[202][202];
class Solution { 
    private:
    int n,m;
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=n || j>=m)
              return 1e9;
        if(i==n-1 && j==m-1)
             return grid[i][j];
        if(dp[i][j]!=-1)
              return dp[i][j];
        int down=grid[i][j]+solve(i+1,j,grid);
        int right=grid[i][j]+solve(i,j+1,grid);
        return  dp[i][j]=min(down,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
    }
};