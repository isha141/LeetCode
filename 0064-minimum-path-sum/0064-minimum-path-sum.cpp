int dp[203][203];
class Solution {
    int n,m; 
    int ans=INT_MAX;
    int  solve(int i,int j,vector<vector<int>>&grid){
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==-1) return 1e9; 
        if(dp[i][j]!=-1) return dp[i][j];
        int temp=grid[i][j];
        grid[i][j]=-1;
       int left=temp+ solve(i+1,j,grid);
        int right=temp+solve(i,j+1,grid); 
        grid[i][j]=temp;
        return dp[i][j]=min(left,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
          n=grid.size();
         m=grid[0].size(); 
        memset(dp,-1,sizeof(dp));
         return  solve(0,0,grid);
        // return ans;
    }
};