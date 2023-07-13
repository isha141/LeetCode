class Solution {
    private:
public:
    int minPathSum(vector<vector<int>>& grid) {
         int n=grid.size();
         int m=grid[0].size(); 
          // memset(dp,-1,sizeof(dp)); 
          vector<vector<int>>dp(n,vector<int>(m,1e9));
          dp[0][0]=grid[0][0];
          for(int i=0;i<n;++i){
              for(int j=0;j<m;++j){
                  if(i==0 && j==0){
                      continue;
                  }
                  int left=INT_MAX;
                  int right=INT_MAX;
                  if(j>0){
                      left=dp[i][j-1]+grid[i][j];
                  }
                  if(i>0){
                      right=dp[i-1][j]+grid[i][j];
                  }
                  dp[i][j]=min(left,right);
              }
          }
        return dp[n-1][m-1];
    }
};