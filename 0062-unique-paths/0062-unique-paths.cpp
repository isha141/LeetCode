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
        memset(dp,-1,sizeof(dp));
        return solve(m-1,n-1);
    }
};