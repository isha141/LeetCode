int dp[102][103];
class Solution { 
    private:
    int solve(int m,int n){
        if(m==0 && n==0)
            return 1;  
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int left=solve(m-1,n);
        int right=solve(m,n-1);
        return dp[m][n]=left+right;
    }
public:
    int uniquePaths(int m, int n) { 
        // memset(dp,-1,sizeof(dp));
        // return solve(m-1,n-1); 
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){ 
                if(i==0 && j==0) continue;
                int left=0;
                int right=0;
                if(i>0){
                    left=dp[i-1][j];
                }
                if(j>0)
                    right=dp[i][j-1];
                dp[i][j]=left+right;
            }
        }
        return dp[m-1][n-1];
    }
};