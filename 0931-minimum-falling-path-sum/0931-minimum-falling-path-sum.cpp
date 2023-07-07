// int dp[101][101];
class Solution { 
    private:
    int n,m; 
    int solve(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(i>=n || j>=m ||  i<0 || j<0 || mat[i][j]==-103) return 1e9;
        if(i==n-1){
            return mat[i][j];
        } 
        // cout<<i<<";;"<<j<<endl;
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
         // int ans=INT_MAX;  
         vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
         for(int i=0;i<m;++i){
            dp[0][i]=mat[0][i];
         }
         for(int i=1;i<n;++i){
             for(int j=0;j<m;++j){
                 int left=mat[i][j];
                 if(j-1>=0)
                     left+=dp[i-1][j-1];
                 else left=INT_MAX;
                 int right=mat[i][j];
                 right+=dp[i-1][j]; 
                 int down=mat[i][j];
                 if(j+1<m){
                     down+=dp[i-1][j+1];
                 }
                 else down=INT_MAX;
                 dp[i][j]=min(left,min(right,down));
             }
         }
         int ans=INT_MAX;
        for(int i=0;i<m;++i){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};