class Solution { 
    private:
    int n,m;
    int solve(int i,int j,vector<vector<int>>&matrix,int prev,vector<vector<int>>&dp){
        if(i<0 || i>=n || j<0 || j>=m || matrix[i][j]<=prev)
             return 0;
        if(dp[i][j]!=-1)
              return dp[i][j];
        return dp[i][j]=1+max({solve(i-1,j,matrix,matrix[i][j],dp),
                               solve(i+1,j,matrix,matrix[i][j],dp),
                               solve(i,j+1,matrix,matrix[i][j],dp),
                               solve(i,j-1,matrix,matrix[i][j],dp)
                              });
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
           n=matrix.size();
           m=matrix[0].size();
           int ans=0;
           vector<vector<int>>dp(n,vector<int>(m,-1));
           for(int i=0;i<n;++i){
               for(int j=0;j<m;++j){
                   ans=max(ans,solve(i,j,matrix,-1,dp));
               }
           }
        return ans;
    }
};