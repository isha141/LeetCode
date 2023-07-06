int dp[102][102];
class Solution {
    private:
    int n,m;
    int solve(int i,int j,vector<vector<int>>vis){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n ) return 0;
        if(dp[i][j]!=0) return dp[i][j]; 
        dp[i][j]++;
        int right=solve(i,j+1,vis);  // right
        // int up=solve(i-1,j,vis);
        int down=solve(i+1,j,vis);  // down
        // vis[i][j]=0;
        return dp[i][j]=(right+down);
    }
public:
    int uniquePaths(int m, int n) { 
        this->n=n;
        this->m=m; 
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<m;++i){
            dp[i][0]=1;
        }
        for(int i=0;i<n;++i){
            dp[0][i]=1;
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                int left=dp[i][j-1];
                int down=dp[i-1][j];
                dp[i][j]=(left+down);
            }
        }
        return dp[m-1][n-1];
    }
};