class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        int count=0; 
        if(g[0][0]==1)
            return 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                     dp[i][j]=1;
                    continue;
                }
                if(g[i][j]==1)
                    dp[i][j]=0;
                else { 
                    int up=0;
                    int right=0;
                    if(i-1>=0)
                        up=dp[i-1][j];
                    if(j-1>=0)
                        right=dp[i][j-1];
                    dp[i][j]=up+right;
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};