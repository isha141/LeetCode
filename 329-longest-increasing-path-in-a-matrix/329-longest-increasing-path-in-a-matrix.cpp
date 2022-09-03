int dp[205][205];
class Solution {  
    int n,m;
    private:
    int solve(int i,int j,vector<vector<int>>&mat,int prev)
    {
        if(i<0  || j<0 || i>=n || j>=m || mat[i][j]<=prev)
            return 0; 
        if(dp[i][j]!=0)
            return dp[i][j];
         
        return  dp[i][j]=1+max({ solve(i+1,j,mat,mat[i][j]), 
                               solve(i-1,j,mat,mat[i][j]),
                              solve(i,j+1,mat,mat[i][j]),
                               solve(i,j-1,mat,mat[i][j])});


    }
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
         n=mat.size();
         m=mat[0].size();
        int ans=0; 
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                ans=max(ans,solve(i,j,mat,INT_MIN));
            }
        }
        return ans;
    }
};