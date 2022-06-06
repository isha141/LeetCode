class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0)); 
        int c=0; 
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){ 
                if(i==j && j==0) continue;
                int bot=0;
                if(i-1>=0)
                   bot=dp[i-1][j];
                int down=0;
                if(j-1>=0)
                   down=dp[i][j-1];
                dp[i][j]=bot+down;
            }
        }
        return dp[m-1][n-1];
    }
};