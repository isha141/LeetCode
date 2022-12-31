class Solution { 
    private:
  int solve(int i,int j,int m,int n,vector<vector<int>>&a,vector<vector<int>>&dp)
    {
        if(i==m-1 && j==n-1){
            if(a[i][j]!=1)
                return 1;
            else
                return 0;
        }
        if(i>=m || j>=n) return 0 ;
        if(a[i][j]==1) return 0;
       if(dp[i][j]!=-1)
          return dp[i][j];
        int left=solve(i+1,j,m,n,a,dp);
      int right=solve(i,j+1,m,n,a,dp);
      return dp[i][j]=left+right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m=a.size(); 
        int n=a[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1)); 
       return  solve(0,0,m,n,a,dp);
    }
};