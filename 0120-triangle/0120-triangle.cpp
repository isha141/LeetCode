int dp[201][201];
class Solution {
    private:
    int n;
    int solve(int i,int col,vector<vector<int>>&tri){
        if(i>=n)
              return 0;
        if(dp[i][col]!=-1)
              return dp[i][col];
        int take=0;
        int not_take=0;
        take=tri[i][col]+min(solve(i+1,col+1,tri),solve(i+1,col,tri));
        return dp[i][col]=take;
    }
public:
    int minimumTotal(vector<vector<int>>& tri) {
        n=tri.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,tri);
    }
};