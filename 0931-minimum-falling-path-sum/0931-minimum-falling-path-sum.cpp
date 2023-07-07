// int dp[101][101];
class Solution { 
    private:
    int n,m; 
    int solve(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(i>=n || j>=m ||  i<0 || j<0 || mat[i][j]==-103) return 1e9;
        if(i==n-1){
            return mat[i][j];
        } 
        cout<<i<<";;"<<j<<endl;
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int temp=mat[i][j];
        // mat[i][j]=-103;
        int left=temp+solve(i+1,j,mat,dp);
        int right=temp+solve(i+1,j+1,mat,dp);
        int down=temp+solve(i+1,j-1,mat,dp);
        // mat[i][j]=temp;
        return dp[i][j]=min(left,min(down,right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
         n=mat.size();
         m=mat[0].size();
         int ans=INT_MAX;  
         // memset(dp,-1,sizeof(dp));
         vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
         for(int i=0;i<m;++i){
             ans=min(ans,solve(0,i,mat,dp));
         }
         return ans;
    }
};