int dp[102][102];
class Solution {
    private:
    int solve(int i,int j){
        if(i==0 && j==0)
              return 1;
        if(i<0 || j<0)
              return 0;
        if(dp[i][j]!=-1)
              return dp[i][j];
        int top=0;
        int left=0;
        top=solve(i-1,j);
        left=solve(i,j-1);
        return dp[i][j]=(top+left);
    }
public:
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(m-1,n-1);
    }
};