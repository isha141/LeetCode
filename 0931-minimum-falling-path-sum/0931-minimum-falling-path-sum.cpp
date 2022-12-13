int dp[101][101];
class Solution { 
    private:
    int n,m;
    int solve(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=n || j>=m || mat[i][j]==10000000)
            return 1e9;
         if(i==n-1)
            return mat[i][j];
        int temp=mat[i][j];
        // mat[i][j]=10000000;
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        return dp[i][j]=temp+min(solve(i+1,j-1,mat,dp),min(solve(i+1,j,mat,dp),solve(i+1,j+1,mat,dp)));
    }
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
         n=mat.size();
         m=mat[0].size();
        // vector<vector<int>>dp(n,vector<int>dp(m,10001));
         int ans=(int)1e9;
            for(int j=0;j<m;++j){
                vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
                ans=min(ans,solve(0,j,mat,dp));
       }
        return ans;
    }
};