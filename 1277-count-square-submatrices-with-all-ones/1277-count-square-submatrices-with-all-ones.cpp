class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size(); 
        int m=mat[0].size(); 
        vector<vector<int>>dp(n,vector<int>(m,0));
         for(int i=0;i<n;++i){
             dp[i][0]=mat[i][0];
         }
        for(int j=0;j<m;++j){
            dp[0][j]=mat[0][j];
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){ 
                if(mat[i][j]==1){
            dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
              }
            }
        }
        int count=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                count+=dp[i][j];
            }
        }
        return count;
    }
};