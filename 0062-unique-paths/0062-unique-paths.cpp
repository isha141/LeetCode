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
        int right=solve(i,j+1,vis);
        // int up=solve(i-1,j,vis);
        int down=solve(i+1,j,vis); 
        // vis[i][j]=0;
        return dp[i][j]=(right+down);
    }
public:
    int uniquePaths(int m, int n) { 
        this->n=n;
        this->m=m; 
        memset(dp,0,sizeof(dp));
        vector<vector<int>>vis(m,vector<int>(n,0));
        return solve(0,0,vis);
    }
};