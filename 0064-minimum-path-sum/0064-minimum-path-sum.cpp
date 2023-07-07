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
          memset(dp,0,sizeof(dp));
          dp[0][0]=grid[0][0];
          for(int i=1;i<m;++i){
              dp[0][i]=grid[0][i]+dp[0][i-1];
          }
          for(int i=1;i<n;++i){
              dp[i][0]=grid[i][0]+dp[i-1][0];
          }
          for(int i=1;i<n;++i){
              for(int j=1;j<m;++j){
                  int left=dp[i-1][j]+grid[i][j];
                  int up=dp[i][j-1]+grid[i][j];
                  dp[i][j]=min(left,up);
              }
          }
        return dp[n-1][m-1];
        
    }
};