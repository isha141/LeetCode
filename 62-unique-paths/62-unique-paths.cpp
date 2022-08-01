class Solution {  
    private:
    int m,n;
    int solve(int i,int j,vector<vector<int>>&dp)
    {
        if(i>=m || j>=n || i<0 || j<0) 
            return 0; 
        if(i==0 && j==0)
            return 1; 
        if(dp[i][j]!=-1) return dp[i][j];
        int l=solve(i-1,j,dp);
        int r=solve(i,j-1,dp);
        return dp[i][j]=l+r;
            
    }
public:
    int uniquePaths(int m, int n) { 
        this->m=m;
        this->n=n; 
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};