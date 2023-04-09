int dp[205][205];
class Solution { 
    private:
    int n,m; 
    int solve(int i,int j,vector<vector<int>>&grid,int prev){
        if(i<0 || i>=n || j<0 || j>=m || prev>=grid[i][j])
              return 0;
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
       return dp[i][j]=1+max({solve(i+1,j,grid,grid[i][j]),
                             solve(i-1,j,grid,grid[i][j]),
                             solve(i,j+1,grid,grid[i][j]),
                            solve(i,j-1,grid,grid[i][j])}); 
    }
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                ans=max(ans,solve(i,j,mat,INT_MIN));
            }
        }
        return ans;
    }
};