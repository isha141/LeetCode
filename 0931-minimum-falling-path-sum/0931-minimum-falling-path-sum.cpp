int dp[101][101];
class Solution {
    int n,m; 
    private:
    int solve(int i,int j,vector<vector<int>>&mat){
        if(i<0 || j<0 || i>=n || j>=m)
            return 1e9;
        if(i==n-1)
            return mat[i][j];
        if(dp[i][j]!=-1) 
            return dp[i][j];
        int l=mat[i][j]+solve(i+1,j,mat);
        int d=mat[i][j]+solve(i+1,j+1,mat);
        int r=mat[i][j]+solve(i+1,j-1,mat);
        return dp[i][j]=min(l,min(d,r));
    }
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        int ans=1e9;
        for(int j=0;j<m;++j){
            memset(dp,-1,sizeof(dp));
            ans=min(ans,solve(0,j,mat));
        }
        return ans;
    }
};


// int f(int i,int j,int n,int m,vector<vector<int>>& a,vector<vector<int>>&dp)
//     {
//         if(j<0 || j>m-1)
//             return 1e9;
        
//         if(i==0)
//             return a[i][j];
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//         int up = a[i][j] + f(i-1,j,n,m,a,dp);
        
//         int ld = a[i][j] + f(i-1,j-1,n,m,a,dp);
        
//         int rd = a[i][j] + f(i-1,j+1,n,m,a,dp);
        
        
//         return dp[i][j]=min(up,min(ld,rd));
        
//     }
    
    
//     int minFallingPathSum(vector<vector<int>>& matrix) {
        
//         int ans=INT_MAX;
        
//         int n=matrix.size();
        
//         int m=matrix[0].size();
        
//         vector<vector<int>>dp(n,vector<int>(m,-1));
        
//         for(int j=0;j<m;j++)
//         {
//             ans=min(ans,f(n-1,j,n,m,matrix,dp));
//         }
        
//         return ans;
        
//     }