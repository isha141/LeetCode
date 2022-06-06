class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m=a.size();
        int n=a[0].size();
     vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                int left=0;
                int up=0;
                if(i>=1)
                    left=dp[i-1][j];
                if(j>=1)
                    up=dp[i][j-1];
                dp[i][j]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};